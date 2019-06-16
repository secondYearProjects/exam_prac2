#ifndef POSTALADDRESS_H
#define POSTALADDRESS_H

#include <string>

class PostalAddress
{
public:
    PostalAddress(std::string country, std::string region, std::string city, std::string road, std::string house, int apartment):
        Country(country),Region(region),City(city),Road(road),House(house),Apartment(apartment){}
    std::string Country;
    std::string Region;
    std::string City;
    std::string Road;
    std::string House;
    int Apartment;
};

#endif // POSTALADDRESS_H
