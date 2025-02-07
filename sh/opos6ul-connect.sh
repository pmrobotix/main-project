#! /bin/bash

#Se connecter une première fois avec ssh robot@[IP] pour enregistrer le mot de passe de la connexion ssh.

IPHOME="192.168.0.205" #WIFI HOME CHO
IPWIFI="192.168.2.107" #WIFI PMX
IPETH0="192.168.2.105" #ETH0 PMX
#IP5GHZ="192.168.3.104" #WIFI 5Ghz PMX5G (LLLLLLLL)
#IP5GHZ="192.168.3.103" #WIFI 5Ghz PMX5G (backup)

IP5GAP="192.168.3.103" #WIFI 5Ghz PMX2_AP_5G (LLLLLLLL) 
 

view_doc()
{
    firefox doc/html/index.html >/dev/null 2>&1 &
}

all()
{
	scp "../Bot_ArmadeusOPOS6UL_ARM/Release/Bot_ArmadeusOPOS6UL_ARM" "../Driver-UnitTest_OPOS6UL_ARM/Debug/Driver-UnitTest_OPOS6UL_ARM" "../Common-UnitTest_OPOS6UL_ARM/Debug/Common-UnitTest_OPOS6UL_ARM" root@$IP:/root/pmx/.
}

tsh()
{
	scp ../sh/*.sh root@$IP:/root/pmx
}

kill()
{
    ssh root@$IP "killall Bot_ArmadeusOPOS6UL_ARM"
}

main()
{
	#/install/armadeus-git/buildroot/output/host/opt/ext-toolchain/arm-none-linux-gnueabihf/bin/strip -s ../Bot_ArmadeusOPOS6UL_ARM/Release/Bot_ArmadeusOPOS6UL_ARM
    #/install/armadeus-7.0/buildroot/output/host/opt/ext-toolchain/arm-linux-gnueabihf/bin/strip -s ../Bot_ArmadeusOPOS6UL_ARM/Release/Bot_ArmadeusOPOS6UL_ARM
    /install/opos6ul-git/buildroot/output/host/opt/ext-toolchain/arm-none-linux-gnueabihf/bin/strip -s ../Bot_ArmadeusOPOS6UL_ARM/Release/Bot_ArmadeusOPOS6UL_ARM
    ssh root@$IP "killall Bot_ArmadeusOPOS6UL_ARM"
	scp "../Bot_ArmadeusOPOS6UL_ARM/Release/Bot_ArmadeusOPOS6UL_ARM" root@$IP:/root/pmx/.
	#ssh root@$IP "strip -s Bot_ArmadeusOPOS6UL_ARM"
}

driver()
{
	scp "../Driver-UnitTest_OPOS6UL_ARM/Debug/Driver-UnitTest_OPOS6UL_ARM" root@$IP:/root/pmx/.
}

common()
{
	scp "../Common-UnitTest_OPOS6UL_ARM/Debug/Common-UnitTest_OPOS6UL_ARM" root@$IP:/root/pmx/.
}

recupcsvhost()
{
    #recup sur le PC Host
	scp root@$IP:/root/pmx/*.* /mnt/hgfs/pmx_xls/.
}

recupcsv()
{
        scp root@$IP:/root/pmx/*.csv /home/pmx/recup/.
}

recupsvg()
{
        scp root@$IP:/root/pmx/*.svg /home/pmx/recup/.
}

connect()
{
	echo $IP
	ssh -t root@$IP "cd /root/pmx ; exec \$SHELL -l"
}


case "$1" in
	5g)
		IP=$IP5GAP
	;;
	eth0)
		IP=$IPETH0
	;;
	wifi)
		IP=$IPWIFI
	;;
	
	home)
		IP=$IPHOME
	;;
	
	*)
		IP=$IPETH0
	;;
esac

case "$2" in
	view-doc)
		view_doc
	;;

	all)
		all
	;;

	tsh)
		tsh
	;;

	main)
		main
	;;

	kill)
		kill
	;;

	driver)
		driver
	;;

	common)
		common
	;;

	connect)
		connect
	;;
        
        recupcsv)
		recupcsv
	;;

        recupsvg)
		recupsvg
	;;

        recupcsvhost)
		recupcsvhost
	;;

	*)
		echo "Usage: $0 {5g|eth0|wifi|home} {connect|main|kill|common|driver|all|tsh|view-doc|recupcsv|recupsvg|recupcsvhost}" >&2
		exit 1
	;;
esac

exit 0
