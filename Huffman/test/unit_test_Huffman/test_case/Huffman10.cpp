#include "../unit_test_Huffman.hpp"

bool UNIT_TEST_Huffman::Huffman10()
{
    string name = "Huffman10";
      //! data ------------------------------------
    InventoryManager manager;
    stringstream output;

    // Car
    List1D<InventoryAttribute> carAttrs;
    carAttrs.add(InventoryAttribute("speed", 123.456));
    carAttrs.add(InventoryAttribute("fuel", 7.89));
    carAttrs.add(InventoryAttribute("engine_temp", 98.76));
    carAttrs.add(InventoryAttribute("tire_pressure", 32.5));
    manager.addProduct(carAttrs, "Car", 2);

    // Battery
    List1D<InventoryAttribute> batteryAttrs;
    batteryAttrs.add(InventoryAttribute("capacity", 250.75));
    batteryAttrs.add(InventoryAttribute("voltage", 12.45));
    batteryAttrs.add(InventoryAttribute("life", 3.5));
    batteryAttrs.add(InventoryAttribute("weight", 5.8));
    manager.addProduct(batteryAttrs, "Battery", 3);

    // Fan
    List1D<InventoryAttribute> fanAttrs;
    fanAttrs.add(InventoryAttribute("rpm", 1230.5));
    fanAttrs.add(InventoryAttribute("power", 45.75));
    fanAttrs.add(InventoryAttribute("noise", 23.33));
    fanAttrs.add(InventoryAttribute("speed_levels", 5.0));
    manager.addProduct(fanAttrs, "Fan", 5);

    // Laptop
    List1D<InventoryAttribute> laptopAttrs;
    laptopAttrs.add(InventoryAttribute("ram", 16.0));
    laptopAttrs.add(InventoryAttribute("storage", 512.5));
    laptopAttrs.add(InventoryAttribute("weight", 1.25));
    laptopAttrs.add(InventoryAttribute("cpu", 2.7));
    laptopAttrs.add(InventoryAttribute("gpu", 6.5));
    manager.addProduct(laptopAttrs, "Laptop", 4);

    // Air Conditioner
    List1D<InventoryAttribute> airconAttrs;
    airconAttrs.add(InventoryAttribute("btu", 12000.0));
    airconAttrs.add(InventoryAttribute("power", 850.5));
    airconAttrs.add(InventoryAttribute("efficiency", 3.75));
    airconAttrs.add(InventoryAttribute("noise", 32.1));
    airconAttrs.add(InventoryAttribute("filter", 2.0));
    manager.addProduct(airconAttrs, "Aircon", 3);

    // Refrigerator
    List1D<InventoryAttribute> fridgeAttrs;
    fridgeAttrs.add(InventoryAttribute("volume", 300.0));
    fridgeAttrs.add(InventoryAttribute("power", 150.0));
    fridgeAttrs.add(InventoryAttribute("noise", 28.0));
    fridgeAttrs.add(InventoryAttribute("temp_range", -18.0));
    manager.addProduct(fridgeAttrs, "Fridge", 2);

    // Output readable format
    InvCompressorTwelve compressor(&manager);
    output << compressor.productToString(carAttrs, "Car") << endl;
    output << compressor.productToString(batteryAttrs, "Battery") << endl;
    output << compressor.productToString(fanAttrs, "Fan") << endl;
    output << compressor.productToString(laptopAttrs, "Laptop") << endl;
    output << compressor.productToString(airconAttrs, "Aircon") << endl;
    output << compressor.productToString(fridgeAttrs, "Fridge") << endl;

    // Build Huffman Tree
    compressor.buildHuffman();

    // Encode
    string encodedCar = compressor.encodeHuffman(carAttrs, "Car");
    string encodedBattery = compressor.encodeHuffman(batteryAttrs, "Battery");
    string encodedFan = compressor.encodeHuffman(fanAttrs, "Fan");
    string encodedLaptop = compressor.encodeHuffman(laptopAttrs, "Laptop");
    string encodedAircon = compressor.encodeHuffman(airconAttrs, "Aircon");
    string encodedFridge = compressor.encodeHuffman(fridgeAttrs, "Fridge");

    output << "Encoded Car: " << encodedCar << endl;
    output << "Encoded Battery: " << encodedBattery << endl;
    output << "Encoded Fan: " << encodedFan << endl;
    output << "Encoded Laptop: " << encodedLaptop << endl;
    output << "Encoded Aircon: " << encodedAircon << endl;
    output << "Encoded Fridge: " << encodedFridge << endl;

    // Decode test: Fan
    string nameOutput;
    List1D<InventoryAttribute> attributesOutput;
    output << "decodeHuffman: " << compressor.decodeHuffman(encodedFan, attributesOutput, nameOutput) << endl;
    output << "decodeHuffman: " << compressor.decodeHuffman(encodedBattery, attributesOutput, nameOutput) << endl;
    output << "decodeHuffman: " << compressor.decodeHuffman(encodedAircon, attributesOutput, nameOutput) << endl;
    output << "decodeHuffman: " << compressor.decodeHuffman(encodedLaptop, attributesOutput, nameOutput) << endl;
    output << attributesOutput.toString()  << endl;


    string expect = "Car:(speed:123.456000), (fuel:7.890000), (engine_temp:98.760000), (tire_pressure:32.500000)\n\
Battery:(capacity:250.750000), (voltage:12.450000), (life:3.500000), (weight:5.800000)\n\
Fan:(rpm:1230.500000), (power:45.750000), (noise:23.330000), (speed_levels:5.000000)\n\
Laptop:(ram:16.000000), (storage:512.500000), (weight:1.250000), (cpu:2.700000), (gpu:6.500000)\n\
Aircon:(btu:12000.000000), (power:850.500000), (efficiency:3.750000), (noise:32.100000), (filter:2.000000)\n\
Fridge:(volume:300.000000), (power:150.000000), (noise:28.000000), (temp_range:-18.000000)\n\
Encoded Car: 06a3ab84a2aa770a8a4a8a5691193bbb5324949879b89969a08bbbb53247a1a0a9a1792a7795aa8089a69993bbbb5324a7a9ab792aaab7a2a298ab78a5a861bbbbb5\n\
Encoded Battery: 05a3a7a77ab908497a3aaa397a9a7908a81b6991bbbb53240ba69ba7a3a078a4a86911bbbb53249ba99478a561bbbbb5324967a9a007a78169abbbbb5\n\
Encoded Fan: 09a3a184abaa958a4a8a5b61bbbbb5324aaa6967ab89116991bbbb5324a1a6a9a278a8a56a5a5bbbb5324a2aa770a929b70b79ba2816bbbbbb5\n\
Encoded Laptop: 01a3aaa7a6aa84aba3958a4936bbbbbb5324a2a7a6aba3a0781a4a861bbbbb5324967a9a007a78a46a81bbbb532497aa988a8699bbbbb5324a0aa9889361bbbbb5\n\
Encoded Aircon: 04a9ab97a6a18402a7988a4a8bbb6bbbbbb5324aaa6967ab89a1b61bbbbb532479494a997a97a197908a56991bbbb5324a1a6a9a278a5a86a4bbbbb532494a99ba77ab8a86bbbbbb5\n\
Encoded Fridge: 09aba90aa07840ba69b989578a5bb6bbbbbb5324aaa6967ab8a41b6bbbbbb5324a1a6a9a278a89a6bbbbbb5324a7795aa92aba3a1a07803a49a6bbbbbb5\n\
decodeHuffman: Fan:(rpm:1230.500000), (power:45.750000), (noise:23.330000), (speed_levels:5.000000)\n\
decodeHuffman: Battery:(capacity:250.750000), (voltage:12.450000), (life:3.500000), (weight:5.800000)\n\
decodeHuffman: Aircon:(btu:12000.000000), (power:850.500000), (efficiency:3.750000), (noise:32.100000), (filter:2.000000)\n\
decodeHuffman: Laptop:(ram:16.000000), (storage:512.500000), (weight:1.250000), (cpu:2.700000), (gpu:6.500000)\n\
[rpm: 1230.500000, power: 45.750000, noise: 23.330000, speed_levels: 5.000000, capacity: 250.750000, voltage: 12.450000, life: 3.500000, weight: 5.800000, btu: 12000.000000, power: 850.500000, efficiency: 3.750000, noise: 32.100000, filter: 2.000000, ram: 16.000000, storage: 512.500000, weight: 1.250000, cpu: 2.700000, gpu: 6.500000]\n"; 

    return printResult(output.str(), expect, name);
}
