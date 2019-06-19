#ifndef POSTALADDRESS_H
#define POSTALADDRESS_H

#include <string>
#include <cstdlib>

class PostalAddress
{
public:
    PostalAddress() {}
    PostalAddress(std::string country, std::string region, std::string city, std::string road, std::string house, int apartment):
        Country(country),Region(region),City(city),Road(road),House(house),Apartment(apartment){}
    std::string Country = "";
    std::string Region = "";
    std::string City = "";
    std::string Road = "";
    std::string House = "";
    int Apartment = -1;
};

class RandomAdressProperties{
public:
    int CountryMaxLen = 10;
    int RegionMaxLen = 10;
    int CityMaxLen = 10;
    int RoadMaxLen = 10;
    int HouseMaxLen = 4;
    int ApartmentMax = 999;
};

class AdressGenerator{
public:
    static PostalAddress getAddress(RandomAdressProperties props){
        return PostalAddress(randomString(props.CountryMaxLen),
                             randomString(props.RegionMaxLen),
                             randomString(props.CityMaxLen),
                             randomString(props.RoadMaxLen),
                             randomString(props.HouseMaxLen),
                             randomInt(props.ApartmentMax));
    }
private:
    AdressGenerator()=delete;

    static std::string randomString(int len){
        static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        std::string s = "";
        for (int i = 0; i < len; ++i) {
            s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return s;
    }

    static int randomInt(int max){
        return rand() % max;
    }
};

#endif // POSTALADDRESS_H
