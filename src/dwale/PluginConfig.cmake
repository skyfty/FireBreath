#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for dwale
#
#\**********************************************************/

set(PLUGIN_NAME "dwale")
set(PLUGIN_PREFIX "DWA")
set(COMPANY_NAME "skyfty")

# ActiveX constants:
set(FBTYPELIB_NAME dwaleLib)
set(FBTYPELIB_DESC "dwale 1.0 Type Library")
set(IFBControl_DESC "dwale Control Interface")
set(FBControl_DESC "dwale Control Class")
set(IFBComJavascriptObject_DESC "dwale IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "dwale ComJavascriptObject Class")
set(IFBComEventSource_DESC "dwale IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 55ea13d8-041c-5ba2-a6cf-743cb47a19a9)
set(IFBControl_GUID e6936c89-ccd5-5d67-b230-69b9351c564c)
set(FBControl_GUID de5f4c92-c370-517f-a0fa-997de968b299)
set(IFBComJavascriptObject_GUID 9b68782f-eeb8-58b9-adad-f39aab7035ef)
set(FBComJavascriptObject_GUID 06d72e39-9ccf-5dd2-b541-fd9fa3bb34e1)
set(IFBComEventSource_GUID 2c74a0ee-9c67-558a-94af-bc6f6ef969da)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 20b4417b-a78b-5107-8d23-e133b91bdf18)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 83c46fe8-255d-5390-b468-6ee501604ed6)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "skyfty.dwale")
if ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "skyfty.com/dwale")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "skyfty.com/dwale_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )

# strings
set(FBSTRING_CompanyName "skyfty")
set(FBSTRING_PluginDescription "read card")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2016 skyfty")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}")
set(FBSTRING_ProductName "dwale")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "dwale")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "dwale_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-dwale")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
