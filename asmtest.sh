#!/bin/bash

SETCOLOR_MY="echo -en \\033[3;36m"
SETCOLOR_NOT_MY="echo -en \\033[3;35m"
SETCOLOR_OK="echo -en \\033[3;32m"
SETCOLOR_KO="echo -en \\033[3;31m"
SETCOLOR_NORMAL="echo -en \\033[0;39m"

echo ""
echo "zother_2.s"
$SETCOLOR_MY
./asm champions/zother_2.s
hexdump -vC champions/zother_2.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/zother_2.s
hexdump -vC champions/zother_2.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
echo "batman.s"
$SETCOLOR_MY
./asm champions/batman.s
hexdump -vC champions/batman.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/batman.s
hexdump -vC champions/batman.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "bee_gees.s"
$SETCOLOR_MY
./asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "bigzork.s"
$SETCOLOR_MY
./asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "fluttershy.s"
$SETCOLOR_MY
./asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "helltrain.s"
$SETCOLOR_MY
./asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "turtle.s"
$SETCOLOR_MY
./asm champions/turtle.s
hexdump -vC champions/turtle.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/turtle.s
hexdump -vC champions/turtle.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "zork.s"
$SETCOLOR_MY
./asm champions/zork.s
hexdump -vC champions/zork.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/zork.s
hexdump -vC champions/zork.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "42.s"
rm -rf my_file not_my_file champions/*.cor
$SETCOLOR_MY
./asm champions/42.s
hexdump -vC champions/42.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/42.s
hexdump -vC champions/42.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Backward.s"
$SETCOLOR_MY
./asm champions/Backward.s
hexdump -vC champions/Backward.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Backward.s
hexdump -vC champions/Backward.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "barriere.s"
$SETCOLOR_MY
./asm champions/barriere.s
hexdump -vC champions/barriere.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/barriere.s
hexdump -vC champions/barriere.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Car.s"
$SETCOLOR_MY
./asm champions/Car.s
hexdump -vC champions/Car.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Car.s
hexdump -vC champions/Car.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Death.s"
$SETCOLOR_MY
./asm champions/Death.s
hexdump -vC champions/Death.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Death.s
hexdump -vC champions/Death.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "ex.s"
$SETCOLOR_MY
./asm champions/ex.s
hexdump -vC champions/ex.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/ex.s
hexdump -vC champions/ex.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Gagnant.s"
$SETCOLOR_MY
./asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "jumper.s"
$SETCOLOR_MY
./asm champions/jumper.s
hexdump -vC champions/jumper.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/jumper.s
hexdump -vC champions/jumper.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "lde.s"
$SETCOLOR_MY
./asm champions/lde.s
hexdump -vC champions/lde.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/lde.s
hexdump -vC champions/lde.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "leeloo.s"
$SETCOLOR_MY
./asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "mat.s"
$SETCOLOR_MY
./asm champions/mat.s
hexdump -vC champions/mat.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/mat.s
hexdump -vC champions/mat.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "maxidef.s"
$SETCOLOR_MY
./asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "mortel.s"
$SETCOLOR_MY
./asm champions/mortel.s
hexdump -vC champions/mortel.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/mortel.s
hexdump -vC champions/mortel.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "new.s"
$SETCOLOR_MY
./asm champions/new.s
hexdump -vC champions/new.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/new.s
hexdump -vC champions/new.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Octobre_Rouge_V4.2.s"
$SETCOLOR_MY
./asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "sebc.s"
$SETCOLOR_MY
./asm champions/sebc.s
hexdump -vC champions/sebc.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/sebc.s
hexdump -vC champions/sebc.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "slider2.s"
$SETCOLOR_MY
./asm champions/slider2.s
hexdump -vC champions/slider2.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/slider2.s
hexdump -vC champions/slider2.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Survivor.s"
$SETCOLOR_MY
./asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "tdc2.s"
$SETCOLOR_MY
./asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "tdc3.s"
$SETCOLOR_MY
./asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "tdc4.s"
$SETCOLOR_MY
./asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Torpille.s"
$SETCOLOR_MY
./asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "toto.s"
$SETCOLOR_MY
./asm champions/toto.s
hexdump -vC champions/toto.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/toto.s
hexdump -vC champions/toto.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "_.s"
$SETCOLOR_MY
./asm champions/_.s
hexdump -vC champions/_.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/_.s
hexdump -vC champions/_.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "_honeybadger.s"
$SETCOLOR_MY
./asm champions/_honeybadger.s
hexdump -vC champions/_honeybadger.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/_honeybadger.s
hexdump -vC champions/_honeybadger.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Asombra.s"
$SETCOLOR_MY
./asm champions/Asombra.s
hexdump -vC champions/Asombra.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Asombra.s
hexdump -vC champions/Asombra.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Bazou.s"
$SETCOLOR_MY
./asm champions/Bazou.s
hexdump -vC champions/Bazou.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Bazou.s
hexdump -vC champions/Bazou.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "big_feet.s"
$SETCOLOR_MY
./asm champions/big_feet.s
hexdump -vC champions/big_feet.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/big_feet.s
hexdump -vC champions/big_feet.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "casimir.s"
$SETCOLOR_MY
./asm champions/casimir.s
hexdump -vC champions/casimir.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/casimir.s
hexdump -vC champions/casimir.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "champ.s"
$SETCOLOR_MY
./asm champions/champ.s
hexdump -vC champions/champ.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/champ.s
hexdump -vC champions/champ.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Code_eater.s"
rm -rf my_file not_my_file champions/*.cor
$SETCOLOR_MY
./asm champions/Code_eater.s
hexdump -vC champions/Code_eater.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Code_eater.s
hexdump -vC champions/Code_eater.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "corelol.s"
$SETCOLOR_MY
./asm champions/corelol.s
hexdump -vC champions/corelol.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/corelol.s
hexdump -vC champions/corelol.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "darksasuke.s"
$SETCOLOR_MY
./asm champions/darksasuke.s
hexdump -vC champions/darksasuke.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/darksasuke.s
hexdump -vC champions/darksasuke.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "doge.s"
$SETCOLOR_MY
./asm champions/doge.s
hexdump -vC champions/doge.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/doge.s
hexdump -vC champions/doge.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Douceur_power.s"
$SETCOLOR_MY
./asm champions/Douceur_power.s
hexdump -vC champions/Douceur_power.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Douceur_power.s
hexdump -vC champions/Douceur_power.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "dubo.s"
$SETCOLOR_MY
./asm champions/dubo.s
hexdump -vC champions/dubo.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/dubo.s
hexdump -vC champions/dubo.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "echo.s"
$SETCOLOR_MY
./asm champions/echo.s
hexdump -vC champions/echo.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/echo.s
hexdump -vC champions/echo.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Eraser.s"
$SETCOLOR_MY
./asm champions/Eraser.s
hexdump -vC champions/Eraser.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Eraser.s
hexdump -vC champions/Eraser.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Explosive_Kitty.s"
$SETCOLOR_MY
./asm champions/Explosive_Kitty.s
hexdump -vC champions/Explosive_Kitty.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Explosive_Kitty.s
hexdump -vC champions/Explosive_Kitty.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "fast.s"
$SETCOLOR_MY
./asm champions/fast.s
hexdump -vC champions/fast.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/fast.s
hexdump -vC champions/fast.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "ForgottenOne.s"
$SETCOLOR_MY
./asm champions/ForgottenOne.s
hexdump -vC champions/ForgottenOne.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/ForgottenOne.s
hexdump -vC champions/ForgottenOne.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "gateau.s"
$SETCOLOR_MY
./asm champions/gateau.s
hexdump -vC champions/gateau.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/gateau.s
hexdump -vC champions/gateau.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "gedeon.s"
$SETCOLOR_MY
./asm champions/gedeon.s
hexdump -vC champions/gedeon.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/gedeon.s
hexdump -vC champions/gedeon.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Hidden.s"
$SETCOLOR_MY
./asm champions/Hidden.s
hexdump -vC champions/Hidden.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Hidden.s
hexdump -vC champions/Hidden.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Horace.s"
$SETCOLOR_MY
./asm champions/Horace.s
hexdump -vC champions/Horace.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Horace.s
hexdump -vC champions/Horace.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Izi_Miaou.s"
$SETCOLOR_MY
./asm champions/Izi_Miaou.s
hexdump -vC champions/Izi_Miaou.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Izi_Miaou.s
hexdump -vC champions/Izi_Miaou.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "jinx.s"
$SETCOLOR_MY
./asm champions/jinx.s
hexdump -vC champions/jinx.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/jinx.s
hexdump -vC champions/jinx.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "justen_bee.s"
$SETCOLOR_MY
./asm champions/justen_bee.s
hexdump -vC champions/justen_bee.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/justen_bee.s
hexdump -vC champions/justen_bee.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "kamelkaze.s"
$SETCOLOR_MY
./asm champions/kamelkaze.s
hexdump -vC champions/kamelkaze.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/kamelkaze.s
hexdump -vC champions/kamelkaze.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Kappa.s"
$SETCOLOR_MY
./asm champions/Kappa.s
hexdump -vC champions/Kappa.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Kappa.s
hexdump -vC champions/Kappa.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "katchup.s"
$SETCOLOR_MY
./asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Kitty_Miaou.s"
$SETCOLOR_MY
./asm champions/Kitty_Miaou.s
hexdump -vC champions/Kitty_Miaou.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Kitty_Miaou.s
hexdump -vC champions/Kitty_Miaou.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Kittystrophic.s"
$SETCOLOR_MY
./asm champions/Kittystrophic.s
hexdump -vC champions/Kittystrophic.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Kittystrophic.s
hexdump -vC champions/Kittystrophic.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "lapsang.s"
$SETCOLOR_MY
./asm champions/lapsang.s
hexdump -vC champions/lapsang.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/lapsang.s
hexdump -vC champions/lapsang.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "le_pet_de_nonne.s"
$SETCOLOR_MY
./asm champions/le_pet_de_nonne.s
hexdump -vC champions/le_pet_de_nonne.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/le_pet_de_nonne.s
hexdump -vC champions/le_pet_de_nonne.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "littlepuppy.s"
$SETCOLOR_MY
./asm champions/littlepuppy.s
hexdump -vC champions/littlepuppy.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/littlepuppy.s
hexdump -vC champions/littlepuppy.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "live.s"
$SETCOLOR_MY
./asm champions/live.s
hexdump -vC champions/live.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/live.s
hexdump -vC champions/live.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "loose.s"
$SETCOLOR_MY
./asm champions/loose.s
hexdump -vC champions/loose.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/loose.s
hexdump -vC champions/loose.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "lou_forktologue.s"
$SETCOLOR_MY
./asm champions/lou_forktologue.s
hexdump -vC champions/lou_forktologue.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/lou_forktologue.s
hexdump -vC champions/lou_forktologue.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Machine-gun.s"
$SETCOLOR_MY
./asm champions/Machine-gun.s
hexdump -vC champions/Machine-gun.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Machine-gun.s
hexdump -vC champions/Machine-gun.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "mandragore.s"
rm -rf my_file not_my_file champions/*.cor
$SETCOLOR_MY
./asm champions/mandragore.s
hexdump -vC champions/mandragore.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/mandragore.s
hexdump -vC champions/mandragore.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "MarineKing.s"
$SETCOLOR_MY
./asm champions/MarineKing.s
hexdump -vC champions/MarineKing.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/MarineKing.s
hexdump -vC champions/MarineKing.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "master_of_puppets.s"
$SETCOLOR_MY
./asm champions/master_of_puppets.s
hexdump -vC champions/master_of_puppets.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/master_of_puppets.s
hexdump -vC champions/master_of_puppets.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "meowluigi.s"
$SETCOLOR_MY
./asm champions/meowluigi.s
hexdump -vC champions/meowluigi.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/meowluigi.s
hexdump -vC champions/meowluigi.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Misaka_Mikoto.s"
$SETCOLOR_MY
./asm champions/Misaka_Mikoto.s
hexdump -vC champions/Misaka_Mikoto.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Misaka_Mikoto.s
hexdump -vC champions/Misaka_Mikoto.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "mise_a_jour_windows95.s"
$SETCOLOR_MY
./asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Noldea.s"
$SETCOLOR_MY
./asm champions/Noldea.s
hexdump -vC champions/Noldea.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Noldea.s
hexdump -vC champions/Noldea.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "O-Maley_Miaou.s"
$SETCOLOR_MY
./asm champions/O-Maley_Miaou.s
hexdump -vC champions/O-Maley_Miaou.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/O-Maley_Miaou.s
hexdump -vC champions/O-Maley_Miaou.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "overwatch.s"
$SETCOLOR_MY
./asm champions/overwatch.s
hexdump -vC champions/overwatch.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/overwatch.s
hexdump -vC champions/overwatch.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "pai_mu_tan.s"
$SETCOLOR_MY
./asm champions/pai_mu_tan.s
hexdump -vC champions/pai_mu_tan.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/pai_mu_tan.s
hexdump -vC champions/pai_mu_tan.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Rainbow_dash.s"
$SETCOLOR_MY
./asm champions/Rainbow_dash.s
hexdump -vC champions/Rainbow_dash.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Rainbow_dash.s
hexdump -vC champions/Rainbow_dash.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "run_Kitty_RUN.s"
$SETCOLOR_MY
./asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "salamahenagalabadoun.s"
$SETCOLOR_MY
./asm champions/salamahenagalabadoun.s
hexdump -vC champions/salamahenagalabadoun.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/salamahenagalabadoun.s
hexdump -vC champions/salamahenagalabadoun.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "sam_2.0.s"
$SETCOLOR_MY
./asm champions/sam_2.0.s
hexdump -vC champions/sam_2.0.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/sam_2.0.s
hexdump -vC champions/sam_2.0.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "sencha.s"
$SETCOLOR_MY
./asm champions/sencha.s
hexdump -vC champions/sencha.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/sencha.s
hexdump -vC champions/sencha.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "skynet.s"
$SETCOLOR_MY
./asm champions/skynet.s
hexdump -vC champions/skynet.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/skynet.s
hexdump -vC champions/skynet.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Stargate0_1.s"
$SETCOLOR_MY
./asm champions/Stargate0_1.s
hexdump -vC champions/Stargate0_1.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Stargate0_1.s
hexdump -vC champions/Stargate0_1.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "tchupka.s"
$SETCOLOR_MY
./asm champions/tchupka.s
hexdump -vC champions/tchupka.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/tchupka.s
hexdump -vC champions/tchupka.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "terminator.s"
$SETCOLOR_MY
./asm champions/terminator.s
hexdump -vC champions/terminator.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/terminator.s
hexdump -vC champions/terminator.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "TheHarvester.s"
$SETCOLOR_MY
./asm champions/TheHarvester.s
hexdump -vC champions/TheHarvester.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/TheHarvester.s
hexdump -vC champions/TheHarvester.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "THUNDER.s"
$SETCOLOR_MY
./asm champions/THUNDER.s
hexdump -vC champions/THUNDER.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/THUNDER.s
hexdump -vC champions/THUNDER.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "ultima.s"
$SETCOLOR_MY
./asm champions/ultima.s
hexdump -vC champions/ultima.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/ultima.s
hexdump -vC champions/ultima.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "ultimate-surrender.s"
$SETCOLOR_MY
./asm champions/ultimate-surrender.s
hexdump -vC champions/ultimate-surrender.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/ultimate-surrender.s
hexdump -vC champions/ultimate-surrender.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Varimathras.s"
$SETCOLOR_MY
./asm champions/Varimathras.s
hexdump -vC champions/Varimathras.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Varimathras.s
hexdump -vC champions/Varimathras.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "Wall.s"
$SETCOLOR_MY
./asm champions/Wall.s
hexdump -vC champions/Wall.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/Wall.s
hexdump -vC champions/Wall.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "wave.s"
$SETCOLOR_MY
./asm champions/wave.s
hexdump -vC champions/wave.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/wave.s
hexdump -vC champions/wave.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor
echo "youforkmytralala.s"
$SETCOLOR_MY
./asm champions/youforkmytralala.s
hexdump -vC champions/youforkmytralala.cor > my_file
$SETCOLOR_NOT_MY
./vm_champs/asm champions/youforkmytralala.s
hexdump -vC champions/youforkmytralala.cor > not_my_file
$SETCOLOR_NORMAL
if (diff my_file not_my_file)
then
    $SETCOLOR_OK
    echo "                                              [OK]"
else
    $SETCOLOR_KO
    echo "                                              [KO]"
fi
$SETCOLOR_NORMAL
echo ""
rm -rf my_file not_my_file champions/*.cor