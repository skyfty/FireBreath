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
功能描述：从JSON字符串中获取类型为布尔的某对象的值。
函数原型：int __stdcall JSONGetBool(const char* json_str, const char* key);
入口参数：	json_str	JSON格式字符串
Key		对象名称
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
功能描述：从JSON字符串中获取类型为字符串的某对象的值。
函数原型：int__stdcall JSONGetString( const char* json_str, const char* key, char* value );
入口参数：	json_str	JSON格式字符串
Key		对象名称
出口参数：value	获取的字符串
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
功能描述：设置模块支持的读卡器型号。默认不支持任何读卡器，使用之前必须调用该函数。。
函数原型：void __stdcall DWSetReaderList( char* list )
入口参数：	list	以逗号(,)分隔的类型标识字符串集合。
出口参数：无
返回值：无
类型	厂家	型号	类型标识
社保卡读卡器	山东神思	SS628T(200)/U100	SS628T(200)
山东神思	SS628T(300)	DCIC32
联迪	SCE-7100	SCE7100
新大陆	NL8000	NL8000
深圳德卡	T6	DCIC32
华大集成	HD100	HD100
深圳明华	DP-R333-SB	DP-R333-SB
深圳明华	DP-123-SB	DP-123-SB
深圳明泰	MT3E-NPD-R3227-NC	MT3E
二合一读卡器	山东明华	HY-U43X	HYU43X
山东神思	SS728M01	SS728M01
山东神思	SS628T10	SS628T10
普天	CP IDMR08/C	CPIDMR08C
深圳明泰	MT3Y-TF-A342	MT3Y
表格1读卡器型号列表
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
功能描述：设置当读卡失败时是否在函数DWSetReaderList所设置的读卡器类型支持列表中搜索已连接的读卡器。将搜到的读卡器类型和通讯方式设为当前配置参数，并尝试再次读卡。
函数原型：int __stdcall DWSetAutoDetect( int auto_detect )
入口参数：	auto_detect	1表示使能，0表示不使能。
出口参数：无
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
功能描述：若未启用自动检测功能，则可以使用该函数设置要读取的读卡器类型，型号，通讯参数等。
函数原型：int __stdcall DWSetReaderPara(int card_type, const char* reader_type, const char* com_type, int port_num, int cpu_card_slot, int psam_card_slot)
入口参数：	card_type	0表示社保卡读卡器，1表示身份证读卡器。
reader_type	读卡器型号。详见上面的表格1。
com_type	通讯类型字符串，SERIAL表示串口，USB表示USB口，AUTO表示自动检测。
port_num	串口号。1表示COM1，2表示COM2，依次类推。
cpu_card_slot	社保卡卡槽号。0表示卡槽1，1表示卡槽2，依次类推。
psam_card_slot	PSAM卡卡槽号。0表示第一个卡槽，1表示第二个卡槽，依次类推。
出口参数：无
返回值：0表示设置成功，-1表示设置失败。
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
功能描述：若未启用自动检测功能，则可以使用该函数设置要读取的读卡器类型，型号，通讯参数等。
函数原型：int __stdcall DWGetReaderPara(int card_type, char* result)
入口参数：	card_type	0表示社保卡读卡器，1表示身份证读卡器。
出口参数：result	JSON字符串。包含的对象为：
属性名	类型	说明
Success	Boolean	操作结果。true表示配置获取成功；false表示失败，失败原因一般为本机未配置过或权限不足。
Message	String	错误信息。获取配置失败原因的描述性文字。
ReaderType	String	读卡器的型号标识。详见型号列表。

ComType	String	“USB”表示使用USB接口、”SERIAL”表示使用RS232串口，”AUTO”表示自动检测。
PortNum	Number	串口号。该参数仅当com_type为”SERIAL”时有效。1表示COM1,2表示COM2，以此类推。
CPUCardSlot	Number	CPU卡槽号。取值为0,1…分别表示卡槽1,卡槽2等，若为其他值，则默认为0。
PSAMCardSlot	Number	PSAM卡槽号.取值为0,1…分别表示卡槽1,卡槽2等，若为其他值，则默认为0。

返回值：0。可忽略。
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
功能描述：获取社保卡的卡号和社保卡中存储的公民身份证号。
函数原型：void __stdcall DWGetSSCardNum( char* info )
入口参数：无。
出口参数：info	JSON字符串，包含的对象为：
名称	类型	说明
Success	Boolean	操作结果。true表示信息获取成功；false表示失败，失败原因在Message属性中。
Message	String	错误信息。获取信息失败原因的描述性文字。
CardNum	String	卡号。9位ASCII字符。
IDNum	String	公民身份证号码。18位数字。

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
2.	获取社保卡基本信息DWGetSSCardInfo
功能描述：获取社保卡的卡号、识别码及用户的基本信息。
函数原型：void __stdcall DWGetSSCardInfo( char* info )
入口参数：无。
出口参数：JSON字符串，包含的对象为：
名称	类型	说明
Success	Boolean	操作结果。true表示信息获取成功；false表示失败，失败原因在Message属性中。
Message	String	错误信息。获取信息失败原因的描述性文字。
CardIDCode	String	卡的识别码。32位HEX字符。
Version	String	规范版本。格式为X.XX，如1.00或2.00等。
CardNum	String	卡号。9位ASCII字符。
IDNum	String	公民身份证号码。18位数字。
Name	String	姓名。GBK编码的汉字字符串，最多15个汉字。
GenderCode	String	性别代码：”1”表示男，”2”表示女，”9”表示未说明性别。符合国家标准。
Gender	String	性别名称。”男”、”女”或”未说明性别”。符合国家标准。
NationalityCode	String	民族代码，由2个数字组成，如”01”表示汉族。符合国家规范。
Nationality	String	民族名称，如汉族等。符合国家规范。
BirthPlace	String	出生地。使用6个数字的行政区域名称表示。
BirthDate	String	出生日期。格式为YYYMMDD。
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
3.	获取社保卡公共信息DWGetSSCardCommonData
功能描述：读取社保卡中的公共信息。
函数原型：void __stdcall DWGetSSCardCommonData( char* info, const char* pin )
入口参数：pin	个人PIN码
出口参数：JSON字符串，包含的对象属性为：
属性名	类型	规范版本	说明
Success	Boolean		操作结果。true表示信息获取成功；false表示失败，失败原因在Message属性中。
Message	String		错误信息。获取信息失败原因的描述性文字。
Version	String		规范版本。
Address	String	2.00	常住所在地地址。GBK编码的汉字字符串。
RegionCode	String	2.00	常住所在地行政区划代码。
Telephone	String	2.00	联系电话。
ContactName	String	2.00	联系人（监护人）姓名。GBK编码的汉字字符串。
ContactTelephone	String	2.00	联系人（监护人）电话
Address	String	1.XX	通讯地址。GBK编码的汉字字符串。
AddressEx	String	1.XX	通讯地址扩展。GBK编码的汉字字符串。
ZipCode	String	1.XX	通讯地址邮政编码。
Telephone	String	1.XX	联系电话。
MobilePhone	String	1.XX	移动电话。
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
1.	获取用户的键盘输入DWGetInputPIN
功能描述：获取用户从键盘输入的PIN密码
函数原型：void __stdcall DWGetInputPIN(const int timeout_second, const int pass_len, const int type, char* result_json)
入参：	timeout_second	用户输入PIN密码的超时时间，单位为秒
pass_len			希望用户输入的PIN密码长度
Type			提示信息类型(1:第一次输入密码; 2: 第二次输入密码)

出口参数：	JSON字符串，包含的对象属性为
属性名	类型	说明
Success	Boolean	操作结果。true表示信息获取成功；false表示失败，失败原因在Message属性中。
Message	String	错误信息。
InputPIN	String	用户输入的PIN密码。
Canceled	Boolean	true表示用户按了取消键。
Timeout	Boolean	true表示用户输入超时了。
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
1.	密码PIN验证DWVerifyPIN
功能描述：验证PIN密码。
函数原型：void __stdcall DWVerifyPIN(const char* pin_str, char* result);
入口参数：pin_str	要验证的用户输入的密码。由4到16个十进制数字组成。
参数名	类型	说明
user_pin	String	要验证的PIN数字字符串。其值为空或长度为4-16的数字字符串。当为空时，如果卡中存在有效的个人密码，则返回进一步允许的重试次数；否则，返回验证成功。
出口参数：result		JSON字符串，包含的对象为：
返回值：Javascript对象，包含的属性为：
属性名	类型	说明
Success	Boolean	true表示验证成功，false表示验证失败。
Message	String	验证失败的原因字符串信息。
SW1SW2	String	错误码，长度为4的HEX字符串。仅当Success为false时有效。
RemainTimes	Integer	校验失败时，表示允许重试的次数。校验成功时，该属性不存在，其他情况为-1。

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
2.	密码PIN修改DWChangePIN
功能描述：修改PIN密码
函数原型：void __stdcall DWChangePIN(const char* new_pin, const char* old_pin, char* result)
入口参数：new_pin	修改后的PIN密码
old_pin	修改前的PIN密码
出口参数：result		JSON字符串，包含的对象为：
属性名	类型	说明
Success	Boolean	true表示密码修改成功，false表示PIN密码修改失败。
Message	String	PIN密码修改失败的原因字符串信息。
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
3.	密码PIN重置DWResetPIN
功能描述：修改PIN密码
函数原型：void __stdcall DWResetPIN(const char* new_pin, char* result)
入口参数：
参数名	类型	说明
new_pin	String	要重置的新PIN密码数字字符串，不应少于4个数字。

出口参数：result		JSON字符串，包含的对象为：
属性名	类型	说明
Success	Boolean	true表示PIN密码重置成功，false表示PIN密码重置失败。
Message	String	重置PIN值失败的原因字符串信息。
SW1SW2	String	错误码，长度为4的HEX字符串。仅当Success为false时有效。
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
1.	获取动态库版本号GetDLLVersion
功能描述：获取动态库版本号。
函数原型：void __stdcall GetDLLVersion(char* version)
入口参数：	无。
出口参数：	version		动态库版本号字符串。
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
2.	打开社保卡读卡器DWReaderOpen
功能描述：打开当前设置的已连接的社保卡读卡器通讯端口。
函数原型：void __stdcall DWReaderOpen(char* info)
入口参数：	无。
3.	出口参数：result		JSON字符串，包含的对象为：
属性名	类型	说明
Success	Boolean	true表示操作成功，false表示操作失败。
Message	String	操作失败的原因字符串信息。
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
4.	关闭社保卡读卡器DWReaderClose
功能描述：关闭已打开的社保卡读卡器。
函数原型：void __stdcall DWReaderClose()
入口参数：	无。
出口参数：	无。
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
5.	IC卡有效性检查DWCheckSSCard
功能描述：IC卡有效性检查，需要机具中有PSAM卡且卡中有IRK国家一级根密钥。
函数原型：void __stdcall DWCheckSSCard(char* result_json)
入口参数：	无。
出口参数：result		JSON字符串，包含的对象为：
属性名	类型	说明
Success	Boolean	IC卡有效性检查是否成功。
Message	String	有效性检查失败的错误信息。
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
