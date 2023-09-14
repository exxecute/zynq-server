echo "Configuring client ip"

if [ -n "$1" ]; then
    echo "Using interface $1"

    CLIENT_IP="192.168.122.99"
    INTERFACE="$1"
else
    echo "No interface"
    exit 0
fi

ifconfig $INTERFACE $CLIENT_IP
ifconfig | grep $INTERFACE
ifconfig | grep $CLIENT_IP