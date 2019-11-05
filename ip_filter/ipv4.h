#ifndef IPV4_H
#define IPV4_H

#include <array>
#include <string>

class Ipv4 {
public:
    static const int bytes_number = 4;
    using Byte = unsigned char;
    enum Byte_number : int;

    Ipv4(const std::array<Byte, bytes_number>&);
    bool operator==(const Ipv4&) const;
    bool operator>(const Ipv4&) const;
    Byte get_byte(const Byte_number) const;
    std::string to_str() const;
private:
    std::array<Byte, bytes_number> bytes_; 
};

std::ostream& operator<<(std::ostream&, const Ipv4&);

#endif