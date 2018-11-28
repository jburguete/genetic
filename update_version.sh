#!/bin/bash
sed -i "s/"$1"\."$2"\."$3"/"$4"\."$5"\."$6"/g" $1.$2.$3/{configure.ac,Doxyfile,README.md}
git mv $1.$2.$3 $4.$5.$6
ln -sf $4.$5.$6/README.md
ln -sf $4.$5.$6 genetic
