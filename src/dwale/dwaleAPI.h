/**********************************************************\

  Auto-generated dwaleAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "dwale.h"

#ifndef H_dwaleAPI
#define H_dwaleAPI

class dwaleAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn dwaleAPI::dwaleAPI(const dwalePtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    dwaleAPI(const dwalePtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
        registerMethod("JSONGetBool", make_method(this, &dwaleAPI::JSONGetBool));
        registerMethod("JSONGetString", make_method(this, &dwaleAPI::JSONGetString));
        registerMethod("DWSetReaderList", make_method(this, &dwaleAPI::DWSetReaderList));
        registerMethod("DWSetAutoDetect", make_method(this, &dwaleAPI::DWSetAutoDetect));
        registerMethod("DWSetReaderPara", make_method(this, &dwaleAPI::DWSetReaderPara));
        registerMethod("DWGetSSCardInfo", make_method(this, &dwaleAPI::DWGetSSCardInfo));
        registerMethod("DWGetSSCardNum", make_method(this, &dwaleAPI::DWGetSSCardNum));
        registerMethod("DWGetSSCardCommonData", make_method(this, &dwaleAPI::DWGetSSCardCommonData));
        registerMethod("DWGetInputPIN", make_method(this, &dwaleAPI::DWGetInputPIN));
        registerMethod("DWVerifyPIN", make_method(this, &dwaleAPI::DWVerifyPIN));
        registerMethod("DWChangePIN", make_method(this, &dwaleAPI::DWChangePIN));
        registerMethod("DWResetPIN", make_method(this, &dwaleAPI::DWResetPIN));
        registerMethod("GetDLLVersion", make_method(this, &dwaleAPI::GetDLLVersion));
        registerMethod("DWReaderOpen", make_method(this, &dwaleAPI::DWReaderOpen));
        registerMethod("DWReaderClose", make_method(this, &dwaleAPI::DWReaderClose));
        registerMethod("DWCheckSSCard", make_method(this, &dwaleAPI::DWCheckSSCard));
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn dwaleAPI::~dwaleAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~dwaleAPI() {};

    dwalePtr getPlugin();

    /*! @function
    ********************************************************************************
    ������������JSON�ַ����л�ȡ����Ϊ������ĳ�����ֵ��
    ����ԭ�ͣ�int __stdcall JSONGetBool(const char* json_str, const char* key);
    ��ڲ�����	json_str	JSON��ʽ�ַ���
    Key		��������
    *******************************************************************************/
    bool JSONGetBool(const std::string& json_str, const std::string& key);

    /*! @function
    ********************************************************************************
    ������������JSON�ַ����л�ȡ����Ϊ�ַ�����ĳ�����ֵ��
    ����ԭ�ͣ�int__stdcall JSONGetString( const char* json_str, const char* key, char* value );
    ��ڲ�����	json_str	JSON��ʽ�ַ���
    Key		��������
    ���ڲ�����value	��ȡ���ַ���
    *******************************************************************************/
    std::string JSONGetString(const std::string& json_str, const std::string& key);

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
    void DWSetReaderList(const std::string& list);

    /*! @function
    ********************************************************************************
    �������������õ�����ʧ��ʱ�Ƿ��ں���DWSetReaderList�����õĶ���������֧���б������������ӵĶ����������ѵ��Ķ��������ͺ�ͨѶ��ʽ��Ϊ��ǰ���ò������������ٴζ�����
    ����ԭ�ͣ�int __stdcall DWSetAutoDetect( int auto_detect )
    ��ڲ�����	auto_detect	1��ʾʹ�ܣ�0��ʾ��ʹ�ܡ�
    ���ڲ�������
    *******************************************************************************/
    bool DWSetAutoDetect(int auto_detect);


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
    bool DWSetReaderPara(int card_type, const std::string&  reader_type, const std::string&  com_type, int port_num, int cpu_card_slot, int psam_card_slot);


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
    std::string DWGetReaderPara(int card_type);

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
    std::string DWGetSSCardNum();



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
    std::string DWGetSSCardInfo();



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
    std::string DWGetSSCardCommonData(const std::string &pin);

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
    std::string DWGetInputPIN(int timeout_second, int pass_len, int type);



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
    std::string DWVerifyPIN(const std::string& pin_str);


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
    std::string DWChangePIN(const std::string& new_pin, const std::string& old_pin);


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
    std::string DWResetPIN(const std::string& new_pin);


    /*! @function
    ********************************************************************************
    1.	��ȡ��̬��汾��GetDLLVersion
    ������������ȡ��̬��汾�š�
    ����ԭ�ͣ�void __stdcall GetDLLVersion(char* version)
    ��ڲ�����	�ޡ�
    ���ڲ�����	version		��̬��汾���ַ�����
    *******************************************************************************/
    std::string GetDLLVersion();


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
    std::string DWReaderOpen();

    /*! @function
    ********************************************************************************
    4.	�ر��籣��������DWReaderClose
    �����������ر��Ѵ򿪵��籣����������
    ����ԭ�ͣ�void __stdcall DWReaderClose()
    ��ڲ�����	�ޡ�
    ���ڲ�����	�ޡ�
    *******************************************************************************/
    void DWReaderClose();


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
    std::string DWCheckSSCard();

private:
    dwaleWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
};

#endif // H_dwaleAPI

