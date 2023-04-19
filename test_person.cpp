#include <iostream>
#include <fstream>

#include "test.pb.h"

#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"

int main() {
    test::Person p;
    p.set_name("test");
    p.set_id(100);
    p.set_email("a@163.com");

    std::string str;
    p.SerializeToString(&str);
    std::cout << "str:[" << str << "]" << std::endl;

    std::ofstream fw;
    fw.open("Person.txt", std::ios::out | std::ios::binary);
    google::protobuf::io::OstreamOutputStream *output = new google::protobuf::io::OstreamOutputStream(&fw);
    google::protobuf::TextFormat::Print(p, output);

    delete output;
    fw.close();

    std::string str1;
    google::protobuf::TextFormat::PrintToString(p, &str1);
    std::cout << "str1:[" << str1 << "]" << std::endl;

    test::Person p1;
    p1.ParseFromString(str);
    std::cout << "name:" << p1.name()
            << ", email:" << p1.email()
            << ",id :" << p1.id() << std::endl;
    return 0;
}
