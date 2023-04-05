#include <iostream>
#include "person.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

using namespace std;
using namespace google::protobuf;

bool minLengthCheck(const std::string &strValue, const uint32_t &dwLenthMin) {
    return strValue.size() < dwLenthMin;
}

int allCheck(const google::protobuf::Message &oMessage){
    const auto *poReflect = oMessage.GetReflection();

    vector<const FieldDescriptor *> vecFD;
    poReflect->ListFields(oMessage, &vecFD);

    for (const auto &poFiled : vecFD) {
        const auto &oFieldRule = poFiled->options().GetExtension(field_rule);
        if (poFiled->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_STRING && !poFiled->is_repeated()) {
            // ������string����ѡ����ظ��ĲŻ�У���ֶγ�������
            const std::string strValue = poReflect->GetString(oMessage, poFiled);
            const std::string strName = poFiled->name();

            if (oFieldRule.length_min()) {
                // �вŽ���У�飬û���򲻽���У��
                if (minLengthCheck(strValue, oFieldRule.length_min())) {
                    cout << "the length of " << strName << " is lower than " << oFieldRule.length_min()<<endl;
                } else {
                    cout << "check min lenth pass"<<endl;
                }
            }
        }
    }
    return 0;
}

int main() {
    Student oStudent1;
    oStudent1.set_name("xiao");

    Student oStudent2;
    oStudent2.set_name("xiaowei");

    allCheck(oStudent1);
    allCheck(oStudent2);

    return 0;
}