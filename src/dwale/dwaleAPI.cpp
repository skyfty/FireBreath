/**********************************************************\

  Auto-generated dwaleAPI.cpp

\**********************************************************/
#include <Windows.h>
#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "dwaleAPI.h"

typedef int(_stdcall *FnJSONGetBool)(const char* json_str, const char* key); FnJSONGetBool ExJSONGetBool;
typedef int(_stdcall *FnJSONGetString)(const char* json_str, const char* key, char* value); FnJSONGetString ExJSONGetString;
typedef void(_stdcall *FnDWSetReaderList)(char* list); FnDWSetReaderList ExDWSetReaderList;
typedef int(_stdcall *FnDWSetAutoDetect)(int auto_detect); FnDWSetAutoDetect ExDWSetAutoDetect;
typedef int(_stdcall *FnDWSetReaderPara)(int card_type, const char*  reader_type, const char*  com_type, int port_num, int cpu_card_slot, int psam_card_slot); FnDWSetReaderPara ExDWSetReaderPara;
typedef int(_stdcall *FnDWGetReaderPara)(int card_type, char* result); FnDWGetReaderPara ExDWGetReaderPara;
typedef void(_stdcall *FnDWGetSSCardNum)(char* info); FnDWGetSSCardNum ExDWGetSSCardNum;
typedef void(_stdcall *FnDWGetSSCardInfo)(char* info); FnDWGetSSCardInfo ExDWGetSSCardInfo;
typedef void(_stdcall *FnDWGetSSCardCommonData)(char* info, const char* pin); FnDWGetSSCardCommonData ExDWGetSSCardCommonData;
typedef void(_stdcall *FnDWGetInputPIN)(int timeout_second, int pass_len, int type, char* result_json); FnDWGetInputPIN ExDWGetInputPIN;
typedef void(_stdcall *FnDWVerifyPIN)(const char* pin_str, char* result); FnDWVerifyPIN ExDWVerifyPIN;
typedef void(_stdcall *FnDWChangePIN)(const char* new_pin, const char* old_pin, char* result); FnDWChangePIN ExDWChangePIN;
typedef void(_stdcall *FnDWResetPIN)(const char* new_pin, char* result); FnDWResetPIN ExDWResetPIN;
typedef void(_stdcall *FnGetDLLVersion)(char* version); FnGetDLLVersion ExGetDLLVersion;
typedef void(_stdcall *FnDWReaderOpen)(char* info); FnDWReaderOpen ExDWReaderOpen;
typedef void(_stdcall *FnDWReaderClose)(); FnDWReaderClose ExDWReaderClose;
typedef void(_stdcall *FnDWCheckSSCard)(char* result_json); FnDWCheckSSCard  ExDWCheckSSCard;

HMODULE CardReaderDLL;
class DWCommon
{
public:
    DWCommon()
    {
        CardReaderDLL = LoadLibrary(L"CardReaderDLL.dll");
        if (CardReaderDLL)
        {
            ExJSONGetBool = (FnJSONGetBool)GetProcAddress(CardReaderDLL, "JSONGetBool");
            ExJSONGetString = (FnJSONGetString)GetProcAddress(CardReaderDLL, "JSONGetString");
            ExDWSetReaderList = (FnDWSetReaderList)GetProcAddress(CardReaderDLL, "DWSetReaderList");
            ExDWSetAutoDetect = (FnDWSetAutoDetect)GetProcAddress(CardReaderDLL, "DWSetAutoDetect");
            ExDWSetReaderPara = (FnDWSetReaderPara)GetProcAddress(CardReaderDLL, "DWSetReaderPara");
            ExDWGetReaderPara = (FnDWGetReaderPara)GetProcAddress(CardReaderDLL, "DWGetReaderPara");
            ExDWGetSSCardNum = (FnDWGetSSCardNum)GetProcAddress(CardReaderDLL, "DWGetSSCardNum");
            ExDWGetSSCardInfo = (FnDWGetSSCardInfo)GetProcAddress(CardReaderDLL, "DWGetSSCardInfo");
            ExDWGetSSCardCommonData = (FnDWGetSSCardCommonData)GetProcAddress(CardReaderDLL, "DWGetSSCardCommonData");
            ExDWGetInputPIN = (FnDWGetInputPIN)GetProcAddress(CardReaderDLL, "DWGetInputPIN");
            ExDWVerifyPIN = (FnDWVerifyPIN)GetProcAddress(CardReaderDLL, "DWVerifyPIN");
            ExDWChangePIN = (FnDWChangePIN)GetProcAddress(CardReaderDLL, "DWChangePIN");
            ExDWResetPIN = (FnDWResetPIN)GetProcAddress(CardReaderDLL, "DWResetPIN");
            ExGetDLLVersion = (FnGetDLLVersion)GetProcAddress(CardReaderDLL, "GetDLLVersion");
            ExDWReaderOpen = (FnDWReaderOpen)GetProcAddress(CardReaderDLL, "GetDLLVersion");
            ExDWReaderOpen = (FnDWReaderOpen)GetProcAddress(CardReaderDLL, "DWReaderOpen");
            ExDWReaderClose = (FnDWReaderClose)GetProcAddress(CardReaderDLL, "DWReaderClose");
            ExDWCheckSSCard = (FnDWCheckSSCard)GetProcAddress(CardReaderDLL, "DWCheckSSCard");
        }
    }
}
gDWCommon;

#define MAX_RESULT_BUFFER 1024

/*! @function
********************************************************************************
������������JSON�ַ����л�ȡ����Ϊ������ĳ�����ֵ��
����ԭ�ͣ�int __stdcall JSONGetBool(const char* json_str, const char* key);
��ڲ�����	json_str	JSON��ʽ�ַ���
Key		��������
*******************************************************************************/
bool dwaleAPI::JSONGetBool(const std::string& json_str, const std::string& key)
{
    if (ExJSONGetBool == 0) {
        throw FB::script_error("Javascript not implement");
    }
    return ExJSONGetBool(json_str.c_str(), key.c_str()) == 0;
}

/*! @function
********************************************************************************
������������JSON�ַ����л�ȡ����Ϊ�ַ�����ĳ�����ֵ��
����ԭ�ͣ�int__stdcall JSONGetString( const char* json_str, const char* key, char* value );
��ڲ�����	json_str	JSON��ʽ�ַ���
Key		��������
���ڲ�����value	��ȡ���ַ���
*******************************************************************************/
std::string dwaleAPI::JSONGetString(const std::string& json_str, const std::string& key)
{
    if (ExJSONGetString == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExJSONGetString(json_str.c_str(), key.c_str(), result.get());
    return result.get();
}

/*! @function
********************************************************************************
��������������ģ��֧�ֵĶ������ͺš�Ĭ�ϲ�֧���κζ�������ʹ��֮ǰ������øú�������
����ԭ�ͣ�void __stdcall DWSetReaderList( char* list )
��ڲ�����	list	�Զ���(,)�ָ������ͱ�ʶ�ַ������ϡ�
���ڲ�������
����ֵ����
����	����	�ͺ�	���ͱ�ʶ
�籣��������	ɽ����˼	SS628T(200)/U100	SS628T(200)
ɽ����˼	SS628T(300)	DCIC32
����	SCE-7100	SCE7100
�´�½	NL8000	NL8000
���ڵ¿�	T6	DCIC32
���󼯳�	HD100	HD100
��������	DP-R333-SB	DP-R333-SB
��������	DP-123-SB	DP-123-SB
������̩	MT3E-NPD-R3227-NC	MT3E
����һ������	ɽ������	HY-U43X	HYU43X
ɽ����˼	SS728M01	SS728M01
ɽ����˼	SS628T10	SS628T10
����	CP IDMR08/C	CPIDMR08C
������̩	MT3Y-TF-A342	MT3Y
���1�������ͺ��б�
*******************************************************************************/
void dwaleAPI::DWSetReaderList(const std::string& list)
{
    if (ExDWSetReaderList == 0) {
        throw FB::script_error("Javascript not implement");
    }
    ExDWSetReaderList(const_cast<char*>(list.c_str()));
}

/*! @function
********************************************************************************
�������������õ�����ʧ��ʱ�Ƿ��ں���DWSetReaderList�����õĶ���������֧���б������������ӵĶ����������ѵ��Ķ��������ͺ�ͨѶ��ʽ��Ϊ��ǰ���ò������������ٴζ�����
����ԭ�ͣ�int __stdcall DWSetAutoDetect( int auto_detect )
��ڲ�����	auto_detect	1��ʾʹ�ܣ�0��ʾ��ʹ�ܡ�
���ڲ�������
*******************************************************************************/
bool dwaleAPI::DWSetAutoDetect(int auto_detect)
{
    if (ExDWSetAutoDetect == 0) {
        throw FB::script_error("Javascript not implement");
    }
    return ExDWSetAutoDetect(auto_detect) == 0;
}


/*! @function
********************************************************************************
������������δ�����Զ���⹦�ܣ������ʹ�øú�������Ҫ��ȡ�Ķ��������ͣ��ͺţ�ͨѶ�����ȡ�
����ԭ�ͣ�int __stdcall DWSetReaderPara(int card_type, const char* reader_type, const char* com_type, int port_num, int cpu_card_slot, int psam_card_slot)
��ڲ�����	card_type	0��ʾ�籣����������1��ʾ���֤��������
reader_type	�������ͺš��������ı��1��
com_type	ͨѶ�����ַ�����SERIAL��ʾ���ڣ�USB��ʾUSB�ڣ�AUTO��ʾ�Զ���⡣
port_num	���ںš�1��ʾCOM1��2��ʾCOM2���������ơ�
cpu_card_slot	�籣�����ۺš�0��ʾ����1��1��ʾ����2���������ơ�
psam_card_slot	PSAM�����ۺš�0��ʾ��һ�����ۣ�1��ʾ�ڶ������ۣ��������ơ�
���ڲ�������
����ֵ��0��ʾ���óɹ���-1��ʾ����ʧ�ܡ�
*******************************************************************************/
bool dwaleAPI::DWSetReaderPara(int card_type, const std::string&  reader_type, const std::string&  com_type, int port_num, int cpu_card_slot, int psam_card_slot)
{
    if (ExDWSetReaderPara == 0) {
        throw FB::script_error("Javascript not implement");
    }
    return ExDWSetReaderPara(card_type, reader_type.c_str(), com_type.c_str(), port_num, cpu_card_slot, psam_card_slot) == 0;
}


/*! @function
********************************************************************************
������������δ�����Զ���⹦�ܣ������ʹ�øú�������Ҫ��ȡ�Ķ��������ͣ��ͺţ�ͨѶ�����ȡ�
����ԭ�ͣ�int __stdcall DWGetReaderPara(int card_type, char* result)
��ڲ�����	card_type	0��ʾ�籣����������1��ʾ���֤��������
���ڲ�����result	JSON�ַ����������Ķ���Ϊ��
������	����	˵��
Success	Boolean	���������true��ʾ���û�ȡ�ɹ���false��ʾʧ�ܣ�ʧ��ԭ��һ��Ϊ����δ���ù���Ȩ�޲��㡣
Message	String	������Ϣ����ȡ����ʧ��ԭ������������֡�
ReaderType	String	���������ͺű�ʶ������ͺ��б�

ComType	String	��USB����ʾʹ��USB�ӿڡ���SERIAL����ʾʹ��RS232���ڣ���AUTO����ʾ�Զ���⡣
PortNum	Number	���ںš��ò�������com_typeΪ��SERIAL��ʱ��Ч��1��ʾCOM1,2��ʾCOM2���Դ����ơ�
CPUCardSlot	Number	CPU���ۺš�ȡֵΪ0,1���ֱ��ʾ����1,����2�ȣ���Ϊ����ֵ����Ĭ��Ϊ0��
PSAMCardSlot	Number	PSAM���ۺ�.ȡֵΪ0,1���ֱ��ʾ����1,����2�ȣ���Ϊ����ֵ����Ĭ��Ϊ0��

����ֵ��0���ɺ��ԡ�
*******************************************************************************/
std::string dwaleAPI::DWGetReaderPara(int card_type)
{
    if (ExDWGetReaderPara == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWGetReaderPara(card_type, result.get());
    return result.get();
}

/*! @function
********************************************************************************
������������ȡ�籣���Ŀ��ź��籣���д洢�Ĺ������֤�š�
����ԭ�ͣ�void __stdcall DWGetSSCardNum( char* info )
��ڲ������ޡ�
���ڲ�����info	JSON�ַ����������Ķ���Ϊ��
����	����	˵��
Success	Boolean	���������true��ʾ��Ϣ��ȡ�ɹ���false��ʾʧ�ܣ�ʧ��ԭ����Message�����С�
Message	String	������Ϣ����ȡ��Ϣʧ��ԭ������������֡�
CardNum	String	���š�9λASCII�ַ���
IDNum	String	�������֤���롣18λ���֡�

*******************************************************************************/
std::string dwaleAPI::DWGetSSCardNum()
{
    if (ExDWGetSSCardNum == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWGetSSCardNum(result.get());
    return result.get();

}



/*! @function
********************************************************************************
2.	��ȡ�籣��������ϢDWGetSSCardInfo
������������ȡ�籣���Ŀ��š�ʶ���뼰�û��Ļ�����Ϣ��
����ԭ�ͣ�void __stdcall DWGetSSCardInfo( char* info )
��ڲ������ޡ�
���ڲ�����JSON�ַ����������Ķ���Ϊ��
����	����	˵��
Success	Boolean	���������true��ʾ��Ϣ��ȡ�ɹ���false��ʾʧ�ܣ�ʧ��ԭ����Message�����С�
Message	String	������Ϣ����ȡ��Ϣʧ��ԭ������������֡�
CardIDCode	String	����ʶ���롣32λHEX�ַ���
Version	String	�淶�汾����ʽΪX.XX����1.00��2.00�ȡ�
CardNum	String	���š�9λASCII�ַ���
IDNum	String	�������֤���롣18λ���֡�
Name	String	������GBK����ĺ����ַ��������15�����֡�
GenderCode	String	�Ա���룺��1����ʾ�У���2����ʾŮ����9����ʾδ˵���Ա𡣷��Ϲ��ұ�׼��
Gender	String	�Ա����ơ����С�����Ů����δ˵���Ա𡱡����Ϲ��ұ�׼��
NationalityCode	String	������룬��2��������ɣ��硱01����ʾ���塣���Ϲ��ҹ淶��
Nationality	String	�������ƣ��纺��ȡ����Ϲ��ҹ淶��
BirthPlace	String	�����ء�ʹ��6�����ֵ������������Ʊ�ʾ��
BirthDate	String	�������ڡ���ʽΪYYYMMDD��
*******************************************************************************/
std::string dwaleAPI::DWGetSSCardInfo()
{
    if (ExDWGetSSCardInfo == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWGetSSCardInfo(result.get());
    return result.get();

}



/*! @function
********************************************************************************
3.	��ȡ�籣��������ϢDWGetSSCardCommonData
������������ȡ�籣���еĹ�����Ϣ��
����ԭ�ͣ�void __stdcall DWGetSSCardCommonData( char* info, const char* pin )
��ڲ�����pin	����PIN��
���ڲ�����JSON�ַ����������Ķ�������Ϊ��
������	����	�淶�汾	˵��
Success	Boolean		���������true��ʾ��Ϣ��ȡ�ɹ���false��ʾʧ�ܣ�ʧ��ԭ����Message�����С�
Message	String		������Ϣ����ȡ��Ϣʧ��ԭ������������֡�
Version	String		�淶�汾��
Address	String	2.00	��ס���ڵص�ַ��GBK����ĺ����ַ�����
RegionCode	String	2.00	��ס���ڵ������������롣
Telephone	String	2.00	��ϵ�绰��
ContactName	String	2.00	��ϵ�ˣ��໤�ˣ�������GBK����ĺ����ַ�����
ContactTelephone	String	2.00	��ϵ�ˣ��໤�ˣ��绰
Address	String	1.XX	ͨѶ��ַ��GBK����ĺ����ַ�����
AddressEx	String	1.XX	ͨѶ��ַ��չ��GBK����ĺ����ַ�����
ZipCode	String	1.XX	ͨѶ��ַ�������롣
Telephone	String	1.XX	��ϵ�绰��
MobilePhone	String	1.XX	�ƶ��绰��
*******************************************************************************/
std::string dwaleAPI::DWGetSSCardCommonData(const std::string &pin)
{
    if (ExDWGetSSCardCommonData == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWGetSSCardCommonData(result.get(), pin.c_str());
    return result.get();

}

/*! @function
********************************************************************************
1.	��ȡ�û��ļ�������DWGetInputPIN
������������ȡ�û��Ӽ��������PIN����
����ԭ�ͣ�void __stdcall DWGetInputPIN(const int timeout_second, const int pass_len, const int type, char* result_json)
��Σ�	timeout_second	�û�����PIN����ĳ�ʱʱ�䣬��λΪ��
pass_len			ϣ���û������PIN���볤��
Type			��ʾ��Ϣ����(1:��һ����������; 2: �ڶ�����������)

���ڲ�����	JSON�ַ����������Ķ�������Ϊ
������	����	˵��
Success	Boolean	���������true��ʾ��Ϣ��ȡ�ɹ���false��ʾʧ�ܣ�ʧ��ԭ����Message�����С�
Message	String	������Ϣ��
InputPIN	String	�û������PIN���롣
Canceled	Boolean	true��ʾ�û�����ȡ������
Timeout	Boolean	true��ʾ�û����볬ʱ�ˡ�
*******************************************************************************/
std::string dwaleAPI::DWGetInputPIN(int timeout_second, int pass_len, int type)
{
    if (ExDWGetInputPIN == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWGetInputPIN(timeout_second, pass_len, type, result.get());
    return result.get();

}



/*! @function
********************************************************************************
1.	����PIN��֤DWVerifyPIN
������������֤PIN���롣
����ԭ�ͣ�void __stdcall DWVerifyPIN(const char* pin_str, char* result);
��ڲ�����pin_str	Ҫ��֤���û���������롣��4��16��ʮ����������ɡ�
������	����	˵��
user_pin	String	Ҫ��֤��PIN�����ַ�������ֵΪ�ջ򳤶�Ϊ4-16�������ַ�������Ϊ��ʱ��������д�����Ч�ĸ������룬�򷵻ؽ�һ����������Դ��������򣬷�����֤�ɹ���
���ڲ�����result		JSON�ַ����������Ķ���Ϊ��
����ֵ��Javascript���󣬰���������Ϊ��
������	����	˵��
Success	Boolean	true��ʾ��֤�ɹ���false��ʾ��֤ʧ�ܡ�
Message	String	��֤ʧ�ܵ�ԭ���ַ�����Ϣ��
SW1SW2	String	�����룬����Ϊ4��HEX�ַ���������SuccessΪfalseʱ��Ч��
RemainTimes	Integer	У��ʧ��ʱ����ʾ�������ԵĴ�����У��ɹ�ʱ�������Բ����ڣ��������Ϊ-1��

*******************************************************************************/
std::string dwaleAPI::DWVerifyPIN(const std::string& pin_str)
{
    if (ExDWVerifyPIN == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWVerifyPIN(pin_str.c_str(), result.get());
    return result.get();

}


/*! @function
********************************************************************************
2.	����PIN�޸�DWChangePIN
�����������޸�PIN����
����ԭ�ͣ�void __stdcall DWChangePIN(const char* new_pin, const char* old_pin, char* result)
��ڲ�����new_pin	�޸ĺ��PIN����
old_pin	�޸�ǰ��PIN����
���ڲ�����result		JSON�ַ����������Ķ���Ϊ��
������	����	˵��
Success	Boolean	true��ʾ�����޸ĳɹ���false��ʾPIN�����޸�ʧ�ܡ�
Message	String	PIN�����޸�ʧ�ܵ�ԭ���ַ�����Ϣ��
*******************************************************************************/
std::string dwaleAPI::DWChangePIN(const std::string& new_pin, const std::string& old_pin)
{
    if (ExDWChangePIN == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWChangePIN(new_pin.c_str(), old_pin.c_str(), result.get());
    return result.get();

}


/*! @function
********************************************************************************
3.	����PIN����DWResetPIN
�����������޸�PIN����
����ԭ�ͣ�void __stdcall DWResetPIN(const char* new_pin, char* result)
��ڲ�����
������	����	˵��
new_pin	String	Ҫ���õ���PIN���������ַ�������Ӧ����4�����֡�

���ڲ�����result		JSON�ַ����������Ķ���Ϊ��
������	����	˵��
Success	Boolean	true��ʾPIN�������óɹ���false��ʾPIN��������ʧ�ܡ�
Message	String	����PINֵʧ�ܵ�ԭ���ַ�����Ϣ��
SW1SW2	String	�����룬����Ϊ4��HEX�ַ���������SuccessΪfalseʱ��Ч��
*******************************************************************************/
std::string dwaleAPI::DWResetPIN(const std::string& new_pin)
{
    if (ExDWResetPIN == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWResetPIN(new_pin.c_str(), result.get());
    return result.get();

}


/*! @function
********************************************************************************
1.	��ȡ��̬��汾��GetDLLVersion
������������ȡ��̬��汾�š�
����ԭ�ͣ�void __stdcall GetDLLVersion(char* version)
��ڲ�����	�ޡ�
���ڲ�����	version		��̬��汾���ַ�����
*******************************************************************************/
std::string dwaleAPI::GetDLLVersion()
{
    if (ExGetDLLVersion == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExGetDLLVersion(result.get());
    return result.get();

}


/*! @function
********************************************************************************
2.	���籣��������DWReaderOpen
�����������򿪵�ǰ���õ������ӵ��籣��������ͨѶ�˿ڡ�
����ԭ�ͣ�void __stdcall DWReaderOpen(char* info)
��ڲ�����	�ޡ�
3.	���ڲ�����result		JSON�ַ����������Ķ���Ϊ��
������	����	˵��
Success	Boolean	true��ʾ�����ɹ���false��ʾ����ʧ�ܡ�
Message	String	����ʧ�ܵ�ԭ���ַ�����Ϣ��
*******************************************************************************/
std::string dwaleAPI::DWReaderOpen()
{
    if (ExDWReaderOpen == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }
    ExDWReaderOpen(result.get());
    return result.get();
}

/*! @function
********************************************************************************
4.	�ر��籣��������DWReaderClose
�����������ر��Ѵ򿪵��籣����������
����ԭ�ͣ�void __stdcall DWReaderClose()
��ڲ�����	�ޡ�
���ڲ�����	�ޡ�
*******************************************************************************/
void dwaleAPI::DWReaderClose()
{
    if (ExDWReaderClose == 0) {
        throw FB::script_error("Javascript not implement");
    }
    ExDWReaderClose();
}

/*! @function
********************************************************************************
5.	IC����Ч�Լ��DWCheckSSCard
����������IC����Ч�Լ�飬��Ҫ��������PSAM���ҿ�����IRK����һ������Կ��
����ԭ�ͣ�void __stdcall DWCheckSSCard(char* result_json)
��ڲ�����	�ޡ�
���ڲ�����result		JSON�ַ����������Ķ���Ϊ��
������	����	˵��
Success	Boolean	IC����Ч�Լ���Ƿ�ɹ���
Message	String	��Ч�Լ��ʧ�ܵĴ�����Ϣ��
*******************************************************************************/
std::string dwaleAPI::DWCheckSSCard()
{
    if (ExDWCheckSSCard == 0) {
        throw FB::script_error("Javascript not implement");
    }
    boost::scoped_array<char> result(new char[MAX_RESULT_BUFFER]);
    if (result.get() == 0) {
        throw FB::script_error("The memory error");
    }

    ExDWCheckSSCard(result.get());
    return result.get();

}

///////////////////////////////////////////////////////////////////////////////
/// @fn dwalePtr dwaleAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
dwalePtr dwaleAPI::getPlugin()
{
    dwalePtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}
