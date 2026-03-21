#!/bin/bash

set -e

. /usr/share/openmediavault/scripts/helper-functions

SERVICE_XPATH_NAME="sleepproxyclient"
SERVICE_XPATH="/config/system/${SERVICE_XPATH_NAME}"

if ! omv_config_exists "${SERVICE_XPATH}"; then
echo "Initializing configuration database ..."
    omv_config_add_node "/config/system" "${SERVICE_XPATH_NAME}"
    omv_config_add_key "${SERVICE_XPATH}" "enable" "1"
    omv_config_add_key "${SERVICE_XPATH}" "interfaces" "all"
    omv_config_add_key "${SERVICE_XPATH}" "leaseTime" "7200"
    omv_config_add_key "${SERVICE_XPATH}" "server" ""
    omv_config_add_key "${SERVICE_XPATH}" "enableRTC" "1"
    omv_config_add_key "${SERVICE_XPATH}" "enableDebug" "0"
fi

exit 0