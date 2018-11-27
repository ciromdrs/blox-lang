

for file in examples/*
do
    if [[ -f $file ]]; then
        echo "Parsing $file"
        ./blox $file
        echo ""
    fi
done

