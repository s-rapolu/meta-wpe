FIRMWARECONTROL_PLATFORM ?= "broadcom"
WPE_FIRMWARECONTROL_EXTRAFLAGS += "${@bb.utils.contains('FIRMWARECONTROL_PLATFORM', 'rpi', '\
     -DPLUGIN_FIRMWARECONTROL_PLATFORM_RPI=ON \
', '', d)}"

WPE_FIRMWARECONTROL_EXTRAFLAGS += "${@bb.utils.contains('FIRMWARECONTROL_PLATFORM', 'broadcom', '\
     -DPLUGIN_FIRMWARECONTROL_PLATFORM_BCM=ON \
', '', d)}"

# Set dependencies
WPE_FIRMWARECONTROL_DEP ?= "${@bb.utils.contains('FIRMWARECONTROL_PLATFORM', 'rpi', 'mfrlibs-rpi', '', d)}"
WPE_FIRMWARECONTROL_DEP ?= "${@bb.utils.contains('FIRMWARECONTROL_PLATFORM', 'broadcom', 'broadcom-mfrlib', '', d)}"

# Additional flags
WPE_FIRMWARECONTROL_AUTOSTART 	?= "true"

# ----------------------------------------------------------------------------

WPE_FIRMWARECONTROL_EXTRAFLAGS += ' \
-DPLUGIN_FIRMWARECONTROL_AUTOSTART=${WPE_FIRMWARECONTROL_AUTOSTART} \
'

# ----------------------------------------------------------------------------

PACKAGECONFIG[firmwarecontrol]     = " \
    -DPLUGIN_FIRMWARECONTROL=ON \
    ${WPE_FIRMWARECONTROL_EXTRAFLAGS} \
    ,-DPLUGIN_FIRMWARECONTROL=OFF,${WPE_FIRMWARECONTROL_DEP}"

# ----------------------------------------------------------------------------

