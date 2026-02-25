//! TODO
#include "app/inventory.h"
// // -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
    attributesMatrix = List2D<InventoryAttribute>();
    productNames = List1D<string>();
    quantities = List1D<int>();
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
    this->attributesMatrix = matrix;
    this->productNames = names;
    this->quantities = quantities;
}

InventoryManager::InventoryManager(const InventoryManager &other)
{
    // TODO
    attributesMatrix = other.attributesMatrix;
    productNames = other.productNames;
    quantities = other.quantities;
}

int InventoryManager::size() const
{
    // TODO
    return productNames.size();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    return attributesMatrix.getRow(index);
}

string InventoryManager::getProductName(int index) const
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    return productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    return quantities.get(index);
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    quantities.set(index, newQuantity);
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // TODO
    attributesMatrix.setRow(attributesMatrix.rows(), attributes);
    productNames.add(name);
    quantities.add(quantity);
}

void InventoryManager::removeProduct(int index)
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    List2D<InventoryAttribute> removedattributesmatrix;
    List1D<string> removedproductname;
    List1D<int> removedquantities;
    for (int i = 0; i < productNames.size(); i++)
    {
        if (i != index)
        {
            removedattributesmatrix.setRow(removedattributesmatrix.rows(), attributesMatrix.getRow(i));
            removedproductname.add(productNames.get(i));
            removedquantities.add(quantities.get(i));
        }
    }
    attributesMatrix = removedattributesmatrix;
    productNames = removedproductname;
    quantities = removedquantities;
}

List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    List1D<string> returnList;
    List1D<string> tmp;
    List1D<InventoryAttribute> queryList;
    List1D<int> quantitiesList;

    for (int i = 0; i < productNames.size(); i++)
    {
        for (int j = 0; j < attributesMatrix.getRow(i).size(); j++)
        {
            InventoryAttribute attr = attributesMatrix.get(i, j);
            if (attr.name == attributeName && attr.value >= minValue && attr.value <= maxValue && quantities.get(i) >= minQuantity)
            {
                queryList.add(attr);
                tmp.add(productNames.get(i));
                quantitiesList.add(quantities.get(i));
            }
        }
    }

    for (int i = 1; i < tmp.size(); i++)
    {
        InventoryAttribute keyAttr = queryList.get(i);
        string keyStr = tmp.get(i);
        int keyQty = quantitiesList.get(i);

        int j = i - 1;

        while (j >= 0 && ((ascending && (queryList.get(j).value > keyAttr.value || (queryList.get(j).value == keyAttr.value && quantitiesList.get(j) > keyQty))) || (!ascending && (queryList.get(j).value < keyAttr.value || (queryList.get(j).value == keyAttr.value && quantitiesList.get(j) < keyQty)))))
        {
            queryList.set(j + 1, queryList.get(j));
            tmp.set(j + 1, tmp.get(j));
            quantitiesList.set(j + 1, quantitiesList.get(j));
            j--;
        }

        queryList.set(j + 1, keyAttr);
        tmp.set(j + 1, keyStr);
        quantitiesList.set(j + 1, keyQty);
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        returnList.add(tmp.get(i));
    }

    return returnList;
}

void InventoryManager::removeDuplicates()
{
    // TODO
    for (int i = 0; i < productNames.size(); i++)
    {
        for (int j = i + 1; j < productNames.size();)
        {
            if (productNames.get(i) == productNames.get(j) &&
                getProductAttributes(i).toString() == getProductAttributes(j).toString())
            {
                quantities.set(i, quantities.get(i) + quantities.get(j));
                removeProduct(j);
            }
            else
            {
                j++;
            }
        }
    }
}
//! Hàm này có gọi removeDuplicates hay không
InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // TODO
    InventoryManager newInven = inv1;
    for (int i = 0; i < inv2.size(); i++)
    {
        newInven.addProduct(inv2.getProductAttributes(i), inv2.getProductName(i), inv2.getProductQuantity(i));
    }
    return newInven;
}

void InventoryManager::split(InventoryManager &section1, InventoryManager &section2, double ratio) const
{
    // TODO
    if (ratio <= 0)
    {
        section1 = InventoryManager();
        section2 = *this;
        return;
    }
    if (ratio >= 1)
    {
        section2 = InventoryManager();
        section1 = *this;
        return;
    }

    double scaledSize = productNames.size() * ratio;
    int new_size = (scaledSize - (int)scaledSize > 1e-6) ? ((int)scaledSize + 1) : (int)scaledSize;
    new_size = abs(new_size);

    section1 = InventoryManager();
    section2 = InventoryManager();

    for (int i = 0; i < new_size; i++)
    {
        section1.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));
    }

    for (int i = new_size; i < productNames.size(); i++)
    {
        section2.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));
    }
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // TODO
    return attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
    return productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
    return quantities;
}

string InventoryManager::toString() const
{
    // TODO
    stringstream ss;
    ss << "InventoryManager[\n";
    ss << "  AttributesMatrix: " << attributesMatrix.toString() << ",\n";
    ss << "  ProductNames: " << productNames.toString() << ",\n";
    ss << "  Quantities: " << quantities.toString() << "\n";
    ss << "]";
    return ss.str();
}