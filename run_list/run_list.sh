 declare -a ele_20 ele_30 ele_50 ele_80 ele_100 ele_120 ele_150 ele_200 ele_250 ele_300 pion_20 pion_30 pion_50 pion_80 pion_100 pion_120 pion_150 pion_200 pion_250 pion_300 mu

ele_20+=(  _436.root)
ele_20+=(  _437.root)
ele_20+=(  _438.root)
ele_20+=(  _439.root)
ele_20+=(  _440.root)
ele_20+=(  _441.root)
ele_20+=(  _442.root)
ele_20+=(  _443.root)
ele_20+=(  _444.root )
ele_20+=(  _445.root )
ele_20+=(  _446.root )
ele_20+=(  _447.root )
ele_20+=(  _449.root )
ele_20+=(  _450.root )
ele_20+=(  _451.root )
ele_20+=(  _452.root )
ele_20+=(  _453.root )
ele_20+=(  _455.root )
ele_20+=(  _984.root )
ele_20+=(  _1012.root )
ele_20+=(  _1014.root )
ele_20+=(  _1015.root )
ele_30+=(  _301.root )
ele_30+=(  _594.root )
ele_30+=(  _595.root )
ele_30+=(  _596.root )
ele_30+=(  _597.root )
ele_30+=(  _599.root )
ele_30+=(  _601.root )
ele_30+=(  _602.root )
ele_30+=(  _603.root )
ele_30+=(  _604.root )
ele_30+=(  _606.root )
ele_30+=(  _607.root )
ele_30+=(  _1007.root )
ele_30+=(  _1008.root )
ele_30+=(  _1010.root )
ele_30+=(  _1011.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )
ele_50+=(  _.root )




path="/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/prompt_reco/v5/prompt_reco"
echo -n "" > 10GeV_list.txt
for file in ${ele_10[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> 10GeV_list.txt
    else
	echo "$path$file not found."
    fi
done

echo -n "" > 30GeV_list.txt
for file in ${ele_30[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> 30GeV_list.txt
    else
	echo "$path$file not found."
    fi
done

echo -n "" > 50GeV_list.txt
for file in ${ele_50[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> 50GeV_list.txt
    else
	echo "$path$file not found."
    fi
done

echo -n "" > 80GeV_list.txt
for file in ${ele_80[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> 80GeV_list.txt
    else
	echo "$path$file not found."
    fi
done

echo -n "" > 100GeV_list.txt
for file in ${ele_100[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> 100GeV_list.txt
    else
	echo "$path$file not found."
    fi
done

echo -n "" > 150GeV_list.txt
for file in ${ele_150[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> 150GeV_list.txt
    else
	echo "$path$file not found."
    fi
done

echo -n "" > mu_list.txt
for file in ${mu[@]}
do
    if [ -f "$path$file" ]
    then
	echo "$path$file" >> mu_list.txt
    else
	echo "$path$file not found."
    fi
done
