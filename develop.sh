app=./testgame

if [ -z ${1+x} ]; then
    echo "Using default"
else
    app=NINAGE-examples/$1;
fi

cd libninage
make install

cd ..

cd $app
make
./app.out

cd ..
