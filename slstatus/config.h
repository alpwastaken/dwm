/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {
	/* function format          argument */
// { run_command, "[ %s] ", "echo \"$(playerctl metadata --format ' {{ artist }} - {{ title }}') $(sh scripts/playerctlstatus.sh)\"" }, 
	// playerctl status | grep "Playing" > /tmp/test.txt && echo 1 || echo 0
	// { run_command, " %s | ", "playerctl status | grep Playing > /tmp/test.txt && echo  || echo  " },
	// { run_command, "  %s | ", "echo $(playerctl metadata --format '{{ artist }} - {{ title }}') && echo $(sh -c \"playerctl status | grep Playing > /tmp/test.txt && echo   ; playerctl status | grep Paused >> /dev/null && echo \" && echo '' || exit)" },
{ run_command, "  %s — ", "echo $(playerctl metadata --format '{{ artist }} - {{ title }}') $(sh -c \"playerctl status | grep Playing > /dev/null && echo   ; playerctl status | grep Paused >> /dev/null && echo \" && echo '' || exit)" },
//	{ cpu_perc, "  %s%% | ", NULL	        },
//	{ cpu_freq, "%sHZ] ", 		NULL			},
/*	{ run_command, "%s] ", "sensors | awk '/^Package/ {print $4}'" }, */
//	{ ram_perc, "[: %s%% ", NULL  	        },
	{ run_command, " %sMiB — ", "free -m | awk '/^Mem/ {print $3}'"},
	{ run_command, "  %s — ", "df -h /dev/disk/by-uuid/4b44d0a8-bf89-41dd-a647-d6b40163e146 | grep \"/dev/\" |  awk '{print $4}'"},
/*	{ run_command, "[: %s] ", "frct"},	*/
	
//	{ run_command, "[  %s] ", "date +\"%d/%m/%Y\"" },
	{ datetime, " %s", "%H:%M:%S -  %a %d %b %Y" },

};
