if [[ "$(playerctl status)" == "Paused" ]]; then
	echo ""
elif [[ "$(playerctl status)" == "Playing" ]]; then
	echo " "
else
	echo -e "n/a"
fi
