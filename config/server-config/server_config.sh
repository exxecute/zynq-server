echo "Configuring server ip"

SERVER_IP="192.168.122.99"

if [ -n "$1" ]; then
    INTERFACE="$1"
else
    INTERFACE="eth0"

echo "Using interface $INTERFACE"

ifconfig $INTERFACE $SERVER_IP
ifconfig | grep $INTERFACE
ifconfig | grep $SERVER_IP
fi