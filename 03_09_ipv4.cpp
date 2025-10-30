#include <cassert>
#include <cstdint>
#include <print>
#include <sstream>

class IpV4 {
public:
    IpV4& operator++() {
        for (int i = COMPONENT_COUNT - 1; i >= 0; --i) {
            m_components[i]++;
            if (m_components[i] != 0) {
                break;
            }
        }
        return *this;
    }

    IpV4 operator++(int) {
        IpV4 old = *this;
        ++*this;
        return old;
    }

    friend bool operator==(IpV4 lhs, IpV4 rhs) {
        for (int i = 0; i < IpV4::COMPONENT_COUNT; ++i) {
            if (lhs.m_components[i] != rhs.m_components[i]) {
                return false;
            }
        }
        return true;
    }

    friend std::istream& operator>>(std::istream& is, IpV4& addr) {
        for (int i = 0; i < IpV4::COMPONENT_COUNT; ++i) {
            int component;
            is >> component;
            addr.m_components[i] = component;

            if (i + 1 < IpV4::COMPONENT_COUNT && is.get() != '.') {
                is.setstate(std::ios::failbit);
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, IpV4 addr) {
        for (int i = 0; i < IpV4::COMPONENT_COUNT; ++i) {
            os << static_cast<int>(addr.m_components[i]);

            if (i + 1 < IpV4::COMPONENT_COUNT) {
                os << '.';
            }
        }
        return os;
    }

private:
    const static int COMPONENT_COUNT = 4;

    std::uint8_t m_components[COMPONENT_COUNT];
};

int main() {
    IpV4 addr;

    std::stringstream stream;
    stream << "12.144.219.255";
    stream >> addr;

    ++addr;

    std::stringstream stream2;
    stream2 << addr;

    std::string result;
    stream2 >> result;

    assert(result == "12.144.220.0");
}
