//Author: Vodohleb04
#include <iostream>
#include <string>
#include <math.h>
#include "HashTable.h"


int main()
{
    HashTable table;
    std::string keys[] = {
        "Ahmed", "Mary", "Alex", "William", "Emila", "Olivia", "James", 
        "Sophia", "Ethan", "Isabella", "Michael", "Emma", "Benjamin", "Ava", 
        "Daniel", "Mia", "Matthew", "Charlotte", "David", "Amelia", "Andrew", 
        "Abigail", "Lucas", "Harper", "Joseph", "Evelyn", "Samuel", "Emily", 
        "Christopher", "Ella", "Jacob", "Grace", "Willy", "Sophie", "Ryan", 
        "Chloe", "Gabriel", "Victoria", "Nicholas", "Zoe", "Luke", "Lily",
        "Nathan", "Lila", "Anthony", "Layla", "Max", "Aria", "Kevin",
        "Avery", "Eric", "Eleanor", "Mark", "Audrey", "Philip", "Hannah",
        "Peter", "Aurora", "Simon", "Bella", "Sean", "Brooklyn", "Henry"
    };
    std::string values[] = {
        "BWM E24 635 csi", "Fiat Punto", "Dodge RAM", "Buick Riviera 1965", "Volkswagen Passat B7", "Ford Scorpio",
        "Mini Clubman", "Mazda RX-7", "Mercedes-Benz CLA", "Mercedes-Benz CLS350", "Honda Civic 8", "BMW e63",
        "BMW X7", "Audi A6", "Volkswagen Golf 8", "Dodge Charger", "Toyota Corolla", "Nissan Skyline R34",
        "Peugeot 308", "Subaru Forester", "Subaru Impreza", "Mitsubishi Lancer", "BMW M5 F90",
        "Mazda 636", "Mercedes-Benz Sprinter", "Ford Crown Victoria", "LADA 21031",
        "Porsche Panamera", "Pontiac Firebird", "Ford Probe", "Lincoln Continental",
        "Cadillac Fleetwood", "Chevrolet Corvair", "Chevrolet Camaro",
        "Chevrolet Corvette C6", "Audi Sport quattro",
        "Toyota MarkII X100", "Mitsubishi Galant", "SAAB 9-3",
        "Volvo 200", "AMC Gremlin", "Opel Diplomat",
        "Nissan Z350", "Mercury Marauder", "Rover 75",
        "Alfa Romeo 156", "Land Rover Defender 110", "BMW e65", "Crysler 300M",
        "Lancia Kappa", "Citroen XM", "Jeep Cherokee XJ", "GMC Suburban",
        "Ford Mustang SN95", "Ford Orion Mark2", "Audi A8L", "BMW e90", "Renault Logan",
        "Jaguar XJ", "Nissan Silvia S14", "Toyota Corolla AE86", "Nissan  Maxima A32", "Lancia Delta S4"
    };
    for (int i = 0; i < 63; i++)
    {
        table.add(keys[i],values[i]);
    }
    std::cout << table << std::endl;
    std::cout << "\n##################################################\n\n";
    std::cout << table.find("Emily") << std::endl;
    std::cout << "\n##################################################\n\n";
    std::cout << table.find("Gabriel") << std::endl;
    std::cout << "\n##################################################\n\n";
    table.remove("Gabriel");
    std::cout << table << std::endl;
    try
    {
        table.find("Gabriel");
    }
    catch(std::out_of_range& ex)
    {
        std::cout << ex.what() << std::endl;
        std::cout << "\n##################################################\n\n";
    }
    std::cout << table.find("Chloe") <<std::endl;
    std::cout << "\n##################################################\n\n";
    table.find("Chloe").setData("Ford GT40");
    std::cout << table.find("Chloe") <<std::endl;
    std::cout << "\n##################################################\n\n";
    std::cout<<table << std::endl;
    std::cout << "\n##################################################\n\n";
    table.logout << table;
    table.logout.close();
    return 0;
}
