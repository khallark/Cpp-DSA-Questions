#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>


// A python List-like container.
class List {
private:
    class iterator;
    // Base case for the recursive function (when no arguments are left)
    void addElements() {}

    // Recursive function to add elements one by one
    template<typename First, typename... Args>
    void addElements(First first, Args... args) {
        container.push_back(new dataTypes(first));  // Add current element
        addElements(args...);  // Recursive call with remaining elements
    }
public:
    class dataTypes {
    private:
        enum class Type { NONE, INT, DOUBLE, STRING, LIST, BOOL, CHAR } _type_;
        int* v1;
        double* v2;
        std::string* v3;
        List* v4;
        bool* v5;
        char* v6;

        void clean() {
            if (_type_ == Type::INT) delete v1;
            else if (_type_ == Type::DOUBLE) delete v2;
            else if (_type_ == Type::STRING) delete v3;
            else if (_type_ == Type::LIST) delete v4;
            else if (_type_ == Type::BOOL) delete v5;
            else if (_type_ == Type::CHAR) delete v6;
            _type_ = Type::NONE;
        }
    public:
        dataTypes() : _type_(Type::NONE), v1(nullptr), v2(nullptr), v3(nullptr), v4(nullptr), v5(nullptr), v6(nullptr) {}
        dataTypes(const int val) : _type_(Type::INT), v1(new int(val)), v2(nullptr), v3(nullptr), v4(nullptr), v5(nullptr), v6(nullptr) {}
        dataTypes(const double val) : _type_(Type::DOUBLE), v1(nullptr), v2(new double(val)), v3(nullptr), v4(nullptr), v5(nullptr), v6(nullptr) {}
        dataTypes(const std::string val) : _type_(Type::STRING), v1(nullptr), v2(nullptr), v3(new std::string(val)), v4(nullptr), v5(nullptr), v6(nullptr) {}
        dataTypes(const char* val) : _type_(Type::STRING), v1(nullptr), v2(nullptr), v4(nullptr), v5(nullptr), v6(nullptr) {
            v3 = new std::string(val);
        }
        dataTypes(const List val) : _type_(Type::LIST), v1(nullptr), v2(nullptr), v3(nullptr), v4(new List(val)), v5(nullptr), v6(nullptr) {}
        dataTypes(const bool val) : _type_(Type::BOOL), v1(nullptr), v2(nullptr), v3(nullptr), v4(nullptr), v5(new bool(val)), v6(nullptr) {}
        dataTypes(const char val) : _type_(Type::CHAR), v1(nullptr), v2(nullptr), v3(nullptr), v4(nullptr), v5(nullptr), v6(new char(val)) {}

        dataTypes(const dataTypes& other) : _type_(other._type_) {
            if (_type_ == Type::INT) v1 = new int(*other.v1);
            else if (_type_ == Type::DOUBLE) v2 = new double(*other.v2);
            else if (_type_ == Type::STRING) v3 = new std::string(*other.v3);
            else if (_type_ == Type::LIST) v4 = new List(*other.v4);
            else if (_type_ == Type::BOOL) v5 = new bool(*other.v5);
            else if (_type_ == Type::CHAR) v6 = new char(*other.v6);
        }

        dataTypes& operator=(const dataTypes& other) {
            if (this != &other) {
                clean();
                _type_ = other._type_;
                if (_type_ == Type::INT) v1 = new int(*other.v1);
                else if (_type_ == Type::DOUBLE) v2 = new double(*other.v2);
                else if (_type_ == Type::STRING) v3 = new std::string(*other.v3);
                else if (_type_ == Type::LIST) v4 = new List(*other.v4);
                else if (_type_ == Type::BOOL) v5 = new bool(*other.v5);
                else if (_type_ == Type::CHAR) v6 = new char(*other.v6);
            }
            return *this;
        }

        dataTypes& operator=(const int val) {
            clean();
            _type_ = Type::INT;
            v1 = new int(val);
            return *this;
        }

        dataTypes& operator=(const double val) {
            clean();
            _type_ = Type::DOUBLE;
            v2 = new double(val);
            return *this;
        }

        dataTypes& operator=(const std::string val) {
            clean();
            _type_ = Type::STRING;
            v3 = new std::string(val);
            return *this;
        }

        dataTypes& operator=(const char* val) {
            clean();
            _type_ = Type::STRING;
            v3 = new std::string(val);
            return *this;
        }

        dataTypes& operator=(const List val) {
            clean();
            _type_ = Type::LIST;
            v4 = new List(val);
            return *this;
        }

        dataTypes& operator=(const bool val) {
            clean();
            _type_ = Type::BOOL;
            v5 = new bool(val);
            return *this;
        }

        dataTypes& operator=(const char val) {
            clean();
            _type_ = Type::CHAR;
            v6 = new char(val);
            return *this;
        }

        dataTypes operator+(const dataTypes other) {
            if((this->_type_ == Type::INT || this->_type_ == Type::DOUBLE || this->_type_ == Type::BOOL || this->_type_ == Type::CHAR)
            && (other._type_ == Type::INT || other._type_ == Type::DOUBLE || other._type_ == Type::BOOL || other._type_ ==Type::CHAR)) {
                double a = *this;
                double b = other;
                return a + b;
            }
            if((this->_type_ == Type::STRING || this->_type_ == Type::CHAR) && 
            (other._type_ == Type::STRING || other._type_ == Type::CHAR)) {
                if(this->_type_ == Type::STRING) {
                    if(other._type_ == Type::STRING) return *this->v3 + *other.v3;
                    else return *this->v3 + *other.v6;
                }
                else if(other._type_ == Type::STRING) return *this->v6 + *other.v3;
            }
            throw std::runtime_error("_TypeError_: Cannot perform addition of the these types");
            return 0;
        }
        dataTypes operator-(const dataTypes other) {
            if((this->_type_ == Type::INT || this->_type_ == Type::DOUBLE || this->_type_ == Type::BOOL || this->_type_ == Type::CHAR)
            && (other._type_ == Type::INT || other._type_ == Type::DOUBLE || other._type_ == Type::BOOL || other._type_ ==Type::CHAR)) {
                double a = *this;
                double b = other;
                return a - b;
            }
            throw std::runtime_error("_TypeError_: Cannot perform addition of the these types");
            return 0;
        }
        dataTypes operator*(const dataTypes other) {
            if((this->_type_ == Type::INT || this->_type_ == Type::DOUBLE || this->_type_ == Type::BOOL || this->_type_ == Type::CHAR)
            && (other._type_ == Type::INT || other._type_ == Type::DOUBLE || other._type_ == Type::BOOL || other._type_ ==Type::CHAR)) {
                double a = *this;
                double b = other;
                return a * b;
            }
            throw std::runtime_error("_TypeError_: Cannot perform addition of the these types");
            return 0;
        }
        dataTypes operator/(const dataTypes other) {
            if((this->_type_ == Type::INT || this->_type_ == Type::DOUBLE || this->_type_ == Type::BOOL || this->_type_ == Type::CHAR)
            && (other._type_ == Type::INT || other._type_ == Type::DOUBLE || other._type_ == Type::BOOL || other._type_ ==Type::CHAR)) {
                double a = *this;
                double b = other;
                return a / b;
            }
            throw std::runtime_error("_TypeError_: Cannot perform addition of the these types");
            return 0;
        }

        dataTypes& operator+=(const dataTypes other) {
            *this = *this + other;
            return *this;
        }
        dataTypes& operator-=(const dataTypes other) {
            *this = *this - other;
            return *this;
        }
        dataTypes& operator*=(const dataTypes other) {
            *this = *this * other;
            return *this;
        }
        dataTypes& operator/=(const dataTypes other) {
            *this = *this / other;
            return *this;
        }

        dataTypes& operator[](int i) {
            if(_type_ == Type::LIST) {
                if(i >= v4->size()) throw std::runtime_error("_IndexError_: Out of bounds");
                return (*v4)[i];
            }
            if(_type_ == Type::STRING) {
                throw std::runtime_error("_AccessError_: Cannot directly access/modify the string's elements using operator[]");
            }
            throw std::runtime_error("Invalid _type_: current _type_ is not List");
        }

        bool operator==(const dataTypes& other) const {
            if(this->_type_ != other._type_) {
                if((this->_type_ == Type::INT || this->_type_ == Type::DOUBLE || this->_type_ == Type::BOOL || this->_type_ == Type::CHAR)
                && (other._type_ == Type::INT || other._type_ == Type::DOUBLE || other._type_ == Type::BOOL || other._type_ == Type::CHAR)) {
                    double a = *this;
                    double b = other;
                    return a == b;
                }
                return false;
            }
            if(this->_type_ == Type::INT) return *this->v1 == *other.v1;
            if(this->_type_ == Type::DOUBLE) return *this->v2 == *other.v2;
            if(this->_type_ == Type::STRING) return *this->v3 == *other.v3;
            if(this->_type_ == Type::LIST) return *this->v4 == *other.v4;
            if(this->_type_ == Type::BOOL) return *this->v5 == *other.v5;
            if(this->_type_ == Type::CHAR) return *this->v6 == *other.v6;
            return true;
        }
        bool operator!=(const dataTypes& other) const {
            if(this->_type_ != other._type_) {
                if((this->_type_ == Type::INT || this->_type_ == Type::DOUBLE || this->_type_ == Type::BOOL || this->_type_ == Type::CHAR)
                && (other._type_ == Type::INT || other._type_ == Type::DOUBLE || other._type_ == Type::BOOL || other._type_ == Type::CHAR)) {
                    double a = *this;
                    double b = other;
                    return a != b;
                }
                return true;
            }
            if(this->_type_ == Type::INT) return *this->v1 != *other.v1;
            if(this->_type_ == Type::DOUBLE) return *this->v2 != *other.v2;
            if(this->_type_ == Type::STRING) return *this->v3 != *other.v3;
            if(this->_type_ == Type::LIST) return *this->v4 != *other.v4;
            if(this->_type_ == Type::BOOL) return *this->v5 != *other.v5;
            if(this->_type_ == Type::CHAR) return *this->v6 != *other.v6;
            return true;
        }

        std::string type() const {
            if(_type_ == Type::INT) return "Type::INT";
            if(_type_ == Type::DOUBLE) return "Type::DOUBLE";
            if(_type_ == Type::STRING) return "Type::STRING";
            if(_type_ == Type::LIST) return "Type::LIST";
            if(_type_ == Type::BOOL) return "Type::BOOL";
            if(_type_ == Type::CHAR) return "Type::CHAR";
            return "";
        }

        void push_back(const dataTypes val) {
            if(_type_ != Type::LIST) {
                throw std::runtime_error("Invalid _type_: current _type_ is not List");
            }
            this->v4->push_back(val);
        }

        // Push the elements of a list indivisually.
        void push_each(const dataTypes val) {
            if(_type_ != Type::LIST) {
                throw std::runtime_error("Invalid _type_: current _type_ is not List");
            }
            if(val.type() != "type: List") {
                throw std::runtime_error("_TypeError_: The argument must be type: List");
            }
            v4->push_each(val);
        }

        void pop_back() {
            if(_type_ != Type::LIST) {
                throw std::runtime_error("Invalid _type_: current _type_ is not List");
            }
            v4->pop_back();
        }

        iterator begin() {
            if(_type_ != Type::LIST) {
                throw std::runtime_error("Invalid _type_: current _type_ is not List");
            }
            return v4->begin();
        }
        iterator end() {
            if(_type_ != Type::LIST) {
                throw std::runtime_error("Invalid _type_: current _type_ is not List");
            }
            return v4->end();
        }
        int size() {
            if(_type_ != Type::LIST) {
                throw std::runtime_error("Invalid _type_: current _type_ is not List");
            }
            return v4->size();
        }

        operator int() const {
            if (_type_ == Type::INT) return *v1;
            if (_type_ == Type::DOUBLE) return *v2;
            if (_type_ == Type::BOOL) return *v5;
            if (_type_ == Type::CHAR) return *v6;
            throw std::runtime_error("Invalid _type_: current _type_ is not int, double, char, bool");
        }

        operator double() const {
            if (_type_ == Type::DOUBLE) return *v2;
            if (_type_ == Type::INT) return *v1;
            if (_type_ == Type::BOOL) return *v5;
            if (_type_ == Type::CHAR) return *v6;
            throw std::runtime_error("Invalid _type_: current _type_ is not int, double, char, bool");
        }

        operator std::string() const {
            if (_type_ == Type::STRING) return *v3;
            throw std::runtime_error("Invalid _type_: current _type_ is not std::string");
        }

        operator List() const {
            if (_type_ == Type::LIST) return *v4;
            throw std::runtime_error("Invalid _type_: current _type_ is not List");
        }

        operator bool() const {
            if (_type_ == Type::BOOL) return *v5;
            if (_type_ == Type::INT) return *v1;
            if (_type_ == Type::DOUBLE) return *v2;
            if (_type_ == Type::CHAR) return *v6;
            throw std::runtime_error("Invalid _type_: current _type_ is not int, double, char, bool");
        }

        operator char() const {
            if (_type_ == Type::CHAR) return *v6;
            if (_type_ == Type::INT) return *v1;
            if (_type_ == Type::DOUBLE) return *v2;
            if (_type_ == Type::CHAR) return *v5;
            throw std::runtime_error("Invalid _type_: current _type_ is not int, double, char, bool");
        }


        friend std::ostream& operator<<(std::ostream& os, const dataTypes& dt) {
            if (dt._type_ == Type::INT) os << *(dt.v1);
            else if (dt._type_ == Type::DOUBLE) os << *(dt.v2);
            else if (dt._type_ == Type::STRING) os << "\"" << *(dt.v3) << "\"";
            else if (dt._type_ == Type::LIST) os << *(dt.v4);
            else if (dt._type_ == Type::BOOL) {
                if(*(dt.v5)) os << "true";
                else os << "false";
            }
            else if(dt._type_ == Type::CHAR) os << "'" << *(dt.v6) << "'";
            else os << "(null)";
            return os;
        }

        ~dataTypes() {
            clean();
        }
    };

private:
    std::vector<dataTypes*> container;

    class iterator {
    private:
        std::vector<dataTypes*>::iterator it;
    public:
        iterator(std::vector<dataTypes*>::iterator ptr) : it(ptr) {}

        dataTypes& operator*() {
            return **it;
        }

        // Post-increment (var++)
        iterator operator++(int) {
            iterator temp = *this;
            ++it;
            return temp;
        }

        // Pre-increment (++var)
        iterator& operator++() {
            ++it;
            return *this;
        }

        // Post-decrement (var--)
        iterator operator--(int) {
            iterator temp = *this;
            --it;
            return temp;
        }

        // Pre-decrement (--var)
        iterator& operator--() {
            --it;
            return *this;
        }

        bool operator==(const iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const iterator& other) const {
            return it != other.it;
        }

        bool operator>(const iterator& other) const {
            return it > other.it;
        }

        bool operator<(const iterator& other) const {
            return it < other.it;
        }
    };

public:
    List() {}
    List(const List& other) {
        for (auto item : other.container) {
            container.push_back(new dataTypes(*item));
        }
    }
    List(const std::initializer_list<List::dataTypes> lst) {
        for(const auto& item : lst) {
            container.push_back(new dataTypes(item));
        }
    }
    // Variadic template constructor (replaces fold expression)
    // WARNING : Don't put an EMPTY List Type itself in the main List using this constructor,
    // use the initializer list constructor, otherwise the result might not be as expected.
    template<typename First, typename... Args>
    List(First first, Args... args) {
        container.push_back(new dataTypes(first));
        addElements(args...);  // Recursively add remaining elements
    }


    List& operator=(const List& other) {
        if (this != &other) {
            while (!container.empty()) {
                pop_back();
            }
            for (auto item : other.container) {
                container.push_back(new dataTypes(*item));
            }
        }
        return *this;
    }

    void push_back(const dataTypes val) {
        container.push_back(new dataTypes(val));
    }

    // Push the elements of a list indivisually.
    void push_each(const dataTypes val) {
        if(val.type() != "type: List")
            throw std::runtime_error("_TypeError_: The argument must be type: List");
        List l = val;
        for(auto i : l) {
            container.push_back(new dataTypes(i));
        }
    }

    void pop_back() {
        if (!container.empty()) {
            delete container.back();
            container.pop_back();
        }
    }

    dataTypes& operator[](int i) {
        if(i >= container.size()) {
            throw std::runtime_error("_IndexError_: Out of bounds");
        } 
        return *(container[i]);
    }

    int size() {
        return container.size();
    }

    
    iterator begin() {
        return iterator(container.begin());
    }
    iterator end() {
        return iterator(container.end());
    }

    bool operator==(const List& other) const {
        if(this->container.size() != other.container.size()) return false;
        for(int i = 0; i < this->container.size(); i++) {
            if(*this->container[i] != *other.container[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const List& other) const {
        if(this->container.size() != other.container.size()) return true;
        for(int i = 0; i < this->container.size(); i++) {
            if(*this->container[i] != *other.container[i]) {
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& dt) {
        os << "[";
        for(int i = 0; i < dt.container.size(); i++) {
            if(i < dt.container.size() - 1) os << *(dt.container[i]) << ", ";
            else os << *(dt.container[i]);
        }
        os << "]";
        return os;
    }

    ~List() {
        while (!container.empty()) {
            pop_back();
        }
    }
};



// PLUS OPERATOR

List::dataTypes operator+(const List::dataTypes& dt, int val) {
    double result = static_cast<double>(dt) + static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator-(const List::dataTypes& dt, int val) {
    double result = static_cast<double>(dt) - static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator*(const List::dataTypes& dt, int val) {
    double result = static_cast<double>(dt) * static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator/(const List::dataTypes& dt, int val) {
    double result = static_cast<double>(dt) / static_cast<double>(val);
    return List::dataTypes(result);
}



List::dataTypes operator+(int val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) + static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator-(int val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) - static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator*(int val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) * static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator/(int val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) / static_cast<double>(dt);
    return List::dataTypes(result);
}



List::dataTypes operator+(const List::dataTypes& dt, double val) {
    double result = static_cast<double>(dt) + val;
    return List::dataTypes(result);
}
List::dataTypes operator-(const List::dataTypes& dt, double val) {
    double result = static_cast<double>(dt) - val;
    return List::dataTypes(result);
}
List::dataTypes operator*(const List::dataTypes& dt, double val) {
    double result = static_cast<double>(dt) * val;
    return List::dataTypes(result);
}
List::dataTypes operator/(const List::dataTypes& dt, double val) {
    double result = static_cast<double>(dt) / val;
    return List::dataTypes(result);
}



List::dataTypes operator+(double val, const List::dataTypes& dt) {
    double result = val + static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator-(double val, const List::dataTypes& dt) {
    double result = val - static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator*(double val, const List::dataTypes& dt) {
    double result = val * static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator/(double val, const List::dataTypes& dt) {
    double result = val / static_cast<double>(dt);
    return List::dataTypes(result);
}



List::dataTypes operator+(const List::dataTypes& dt, char val) {
    if(dt.type() != "type: string") {
        double result = static_cast<double>(dt) + static_cast<double>(val);
        return List::dataTypes(result);
    }
    std::string result = std::string(dt) + val;
    return List::dataTypes(result);
}
List::dataTypes operator-(const List::dataTypes& dt, char val) {
    double result = static_cast<double>(dt) - static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator*(const List::dataTypes& dt, char val) {
    double result = static_cast<double>(dt) * static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator/(const List::dataTypes& dt, char val) {
    double result = static_cast<double>(dt) / static_cast<double>(val);
    return List::dataTypes(result);
}



List::dataTypes operator+(char val, const List::dataTypes& dt) {
    if(dt.type() != "type: string") {    
        double result = static_cast<double>(val) + static_cast<double>(dt);
        return List::dataTypes(result);
    }
    std::string result = std::string(1, val) + std::string(dt);
    return List::dataTypes(result);
}
List::dataTypes operator-(char val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) - static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator*(char val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) * static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator/(char val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) / static_cast<double>(dt);
    return List::dataTypes(result);
}



List::dataTypes operator+(const List::dataTypes& dt, bool val) {
    double result = static_cast<double>(dt) + static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator-(const List::dataTypes& dt, bool val) {
    double result = static_cast<double>(dt) - static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator*(const List::dataTypes& dt, bool val) {
    double result = static_cast<double>(dt) * static_cast<double>(val);
    return List::dataTypes(result);
}
List::dataTypes operator/(const List::dataTypes& dt, bool val) {
    double result = static_cast<double>(dt) / static_cast<double>(val);
    return List::dataTypes(result);
}



List::dataTypes operator+(bool val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) + static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator-(bool val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) - static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator*(bool val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) * static_cast<double>(dt);
    return List::dataTypes(result);
}
List::dataTypes operator/(bool val, const List::dataTypes& dt) {
    double result = static_cast<double>(val) / static_cast<double>(dt);
    return List::dataTypes(result);
}



List::dataTypes operator+(const List::dataTypes dt, const std::string& str) {
    std::string result = std::string(dt) + str;
    return List::dataTypes(result);
}



List::dataTypes operator+(const std::string str, const List::dataTypes& dt) {
    std::string result = str + std::string(dt);
    return List::dataTypes(result);
}



List::dataTypes operator+(const List::dataTypes dt, const char* str) {
    std::string result = std::string(dt) + str;
    return List::dataTypes(result);
}



List::dataTypes operator+(const char* str, const List::dataTypes& dt) {
    std::string result = str + std::string(dt);
    return List::dataTypes(result);
}