echo "Configuring server ip"

SERVER_IP="192.168.122.115"

if [ -n "$1" ]; then
    INTERFACE="$1"
else
    INTERFACE="eth0"
fi

echo "Using interface $INTERFACE"

ifconfig $INTERFACE $SERVER_IP
ifconfig | grep $INTERFACE
ifconfig | grep $SERVER_IP