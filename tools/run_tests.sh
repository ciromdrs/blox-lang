

for file in examples/*
do
    if [[ -f $file ]]; then
        echo "Parsing $file"
        ./a.out $file
        echo ""
    fi
done

