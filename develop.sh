app=./testgame

if [ -z ${1+x} ]; then
    echo "Using default"
    #echo "var is unset"; exit 1;
else
    app=NINAGE-examples/$1;
fi

cd libninage
make install

cd ..

cd $app
make
./game.out

cd ..
