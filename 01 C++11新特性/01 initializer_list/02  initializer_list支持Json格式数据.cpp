#include <vector>
#include <initializer_list>
#include <iostream>

enum class jsonType {
    Int = 0,
    String = 1
};

struct jsonNode{
public:
    jsonNode(std::string key,std::string value) :
        m_type(jsonType::String),m_key(key),m_value(value) {
        std::cout <<"jsonNode(std::string,std::string)..." << std::endl;
    }

    jsonNode(std::string key,double value) :
        m_type(jsonType::Int),m_key(key),m_value(std::to_string(value)){
            std::cout << "jsonNode(std::string,double)..." << std::endl;
    }
public:
    jsonType m_type;
    std::string m_key;
    std::string m_value;
};

class json {
public:
    static json& array(std::initializer_list<jsonNode> nodes){
        return m_json;
    }
private:
    std::vector<jsonNode> m_nodes;
    static json m_json;
};

json json::m_json;

int main(){
    json object = json::array({{"IP", "192.168.138.76"}, {"Port", 82} });

    return 0;
}