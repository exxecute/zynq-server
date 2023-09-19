if [ -n "$1" ]; then
    DEVICE="$1"
else
    echo "No dev"
    exit 0
fi

chmod 666 $DEVICE
minicom -D $DEVICE minirc.minicom-config