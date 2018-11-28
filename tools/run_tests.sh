

for file in examples/*
do
    if [[ -f $file ]]; then
        echo "Parsing $file"
        ./blox test $file
        echo ""
    fi
done

