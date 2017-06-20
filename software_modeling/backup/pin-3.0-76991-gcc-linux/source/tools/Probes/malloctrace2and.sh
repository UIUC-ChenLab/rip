#!/system/bin/sh
if $1 -t $2 -- $3 > $4 2>&1; then
    # Use short-circuit evaluation to exit in case of error
    $5 Allocated $4 || exit $?
    $6 $4 || exit $?
else
    if [ "$?" == 13 ]; then
        $5 "Error: dlsym and/or dlopen not found" $4 || exit $?
        exit 0
    else
        exit $?
    fi
fi
