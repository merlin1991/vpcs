/*
 * Copyright (c) 2007-2012, Paul Meng (mirnshi@gmail.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
**/

#include <stdio.h>
#include <string.h>
#include "help.h"

int help_clear(int argc, char **argv)
{
	printf( "\n\033[1mclear [ip|ipv6|arp|neighbor|hist]\033[0m\n"
		"            clear ip/ipv6 address, arp/neighbor table, command history\n");
			
	return 1;
}


int help_echo(int argc, char **argv)
{
	return 1;
}

int help_hist(int argc, char **argv)
{
	return 1;
}

int help_ip(int argc, char **argv)
{
	
	if (!strncmp(argv[0], "dhcp", strlen(argv[0])) ||
	    (argc == 3 && !strncmp(argv[1], "dhcp", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2]))))) {
		printf( "\n\033[1mip dhcp [-options]\033[0m, Attempt to obtain IPv4 address, mask, gateway and DNS via DHCP\n"
			"          -d         Show DHCP packet decode\n"
			"          -r         Renew DHCP lease\n"
			"          -x         Release DHCP lease\n");
		return 1;
	}

	if (argc == 3 && !strncmp(argv[1], "mtu", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
	    	printf("\n\033[1mip mtu <value>\033[0m,  set IPv4 MTU to <value>, at least 576.  IPv6 has a minimum MTU of 1280\n");
		return 1;    	
	}

	if (argc == 3 && !strncmp(argv[1], "dns", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
	    	printf("\n\033[1mip dns <ip>\033[0m,  set DNS server <ip>, delete if <ip> is '0'\n");
		return 1;    	
	}


	printf( "\n\033[1mip [arguments]\033[0m, Configure VPC's IP settings\n"
		"    <address> [/<mask>] [<gateway>]\n"
		"    <address> [<gateway>] [/<mask>]\n"
		"                     set the VPC's ip, default gateway ip and network mask\n"
		"                     Default IPv4 mask is /24, IPv6 is /64. In the ether mode, \n"
		"                     the ip of the tapx is the maximum host ID of the subnet.\n"
		"                     \033[1mip 10.1.1.70 /26 10.1.1.65\033[0m  set the VPC's ip to 10.1.1.70, \n"
		"                     the gateway ip to 10.1.1.65, the netmask to 255.255.255.192, \n"
		"                     the tapx ip to 10.1.1.126 in the ether mode.\n"
		"                     </mask> may be written as /26, 26 or 255.255.255.192\n"
		"    auto             Attempt to obtain IPv6 address, mask and gateway using SLAAC\n"
		"    dhcp [-options]  Attempt to obtain IPv4 address, mask, gateway and DNS via DHCP\n"
		"          -d         Show DHCP packet decode\n"
		"          -r         Renew DHCP lease\n"
		"          -x         Release DHCP lease\n"
		"    dns <ip>         set DNS server <ip>, delete if <ip> is '0'\n"
		"    mtu <value>      set IPv4 MTU to <value>, at least 576. \n"
		"    show             Show IPv4 details. Same as \033[1mshow ip\033[0m\n");

	return 1;
}

int help_load(int argc, char **argv)
{
	printf( "\n\033[1mload <filename>\033[0m, Load the configuration/script from the file <filename>.  When the file\n"
		"                 is loaded, commands will displayed before being executed if the state\n"
		"                 of the echo flag is on.  See \033[1mset echo\033[0m\n");
		
	return 1;
}

int help_neighbor(int argc, char **argv)
{
	return 1;
}

int help_ping(int argc, char **argv)
{

	printf( "\n\033[1mping <host> [-options]\033[0m, Ping the network <host>. <host> can be an ip address or name\n"
		"                    Using names requires DNS to be set.\n"
		"                    Use Ctrl+C to stop the command\n"
		"     -1             ICMP mode, default\n"
		"     -2             UDP mode\n"                                                
		"     -3             TCP mode\n"
		"     -P <protocol>  Same as above, setting ip protocol\n"
		"                    1 - icmp, 17 - udp, 6 - tcp\n"
		"     -c <count>     packet count, default 5\n"
		"     -l <size>      data size\n"
		"     -T <ttl>       set TTL, default 64\n"
		"     -s <port>      source port\n"
		"     -p <port>      destination port\n"
		"     -f <flag>      tcp head flag, |C|E|U|A|P|R|S|F|\n"
		"                              bits |7 6 5 4 3 2 1 0|\n"
		"     -t             send packet until interrupt by Ctrl+C\n"
		"     -i <ms>        wait <ms> milliseconds between sending each packet\n"
		"     -w <ms>        wait <ms> milliseconds to receive the response\n");
		
	return 1;
}

int help_trace(int argc, char **argv)
{
	printf( "\n\033[1mtrace <host> [-options]\033[0m, Print the path take to network <host>.\n"
		"                         <host> can be an ip address or name\n"
		"                         Using names requires DNS to be set.\n"
		"                         Use Ctrl+C to stop the command.\n"
		"          -P <protocol>  Use IP <protocol> in trace packets\n"
		"                         1 - icmp, 17 �C udp (default), 6 - tcp  \n"                                       
		"          -m <ttl>       maximum TTL, default 8\n"
		"          <ttl>          Same as -m option, compatible with the old version\n");
                 
	return 1;
}

int help_rlogin(int argc, char **argv)
{
	printf( "\n\033[1mrlogin [<ip>] <port>\033[0m, Telnet to <port> at <ip> (def 127.0.0.1) relative to HOST PC\n"
		"                                      To attach to the console of a virtual router running on\n"
		"                                      port 2000 of this host PC, use rlogin 2000. To attach to\n"
		"                                      the console of a virtual router running on port 2004 of a\n"
		"                                      remote host 10.1.1.1, use rlogin 10.1.1.1 2004\n");
	return 1;
}

int help_save(int argc, char **argv)
{
	printf( "\n\033[1msave <filename>\033[0m, Save the configuration to the file <filename>.\n");

	return 1;
}

int help_set(int argc, char **argv)
{
	if (argc == 3 && !strncmp(argv[1], "dump", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
	    	printf( "\n\033[1mdump [detail|mac|raw|all|off]\033[0m set the packet dump flag for this VPC\n"
	    		"                           detail  print protocol\n"
	    		"                           mac     print ether address\n"
			"                           raw     print the first 40 bytes\n"
			"                           all     all the packets including incoming\n"
			"                                   must use [detail|mac|raw] as well as 'all'\n"
			"                           off     clear all the flags\n");   
		
		return 1;
	}
	
	if (argc == 3 && !strncmp(argv[1], "echo", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
		printf( "\n\033[1mset echo [on|off]\033[0m, Sets the state of the echo flag used when loading script files.\n"
			"                   See \033[1mload <filename>\033[0m.\n");
	    	return 1;
	}
	
	printf( "\n\033[1mset [lport|rport|rhost|pcname|echo|dump]\033[0m\n"
		"    lport <port>                   local port\n"
		"    rport <port>                   remote peer port\n"
		"    rhost <ip>                     remote peer host IPv4 address\n"
		"    pcname <name>                  rename the current VPC\n"
		"    echo [on|off]                  set echoing on or off during script execution\n"
		"    dump [detail|mac|raw|all|off]  set the packet dump flag for this VPC\n"
		"                                   detail, print protocol\n"
		"                                   mac, print ether address\n"
		"                                   raw, print the first 40 bytes\n"
		"                                   all, all the packets including incoming\n"
		"                                        must use [detail|mac|raw] as well as 'all'\n"
		"                                   off, clear all the flag\n");
        
	return 1;
}

int help_show(int argc, char **argv)
{
	if (argc == 3 && !strncmp(argv[1], "arp", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
		printf( "\n\033[1mshow arp [<digit>|all]\033[0m, Show arp table for VPC <digit> (default this VPC) or all VPCs\n");
		return 1;
	}
	
	if (argc == 3 && !strncmp(argv[1], "dump", strlen(argv[1])) && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
		printf( "\n\033[1mshow dump [<digit>|all]\033[0m, Show dump flags for VPC <digit> (default this VPC) or all VPCs\n");
		return 1;
	}

	if (argc == 3 && !strcmp(argv[1], "ip") && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
		printf( "\n\033[1mshow ip [<digit>|all]\033[0m, Show IPv4 details for VPC <digit> (default this VPC) or all VPCs\n"
			"                       Shows VPC Name, IP address, mask, gateway, DNS, MAC, lport, \n"
			"                       rhost:rport and MTU\n");
		return 1;
	}
	
	if (argc == 3 && !strcmp(argv[1], "ipv6") && 
	    (!strcmp(argv[2], "?") || !strncmp(argv[2], "help", strlen(argv[2])))) {
		printf( "\n\033[1mshow ip [<digit>|all]\033[0m, Show IPv4 details for VPC <digit> (default this VPC) or all VPCs\n"
			"                       Shows VPC Name, IP address, mask, gateway, DNS, MAC, lport, \n"
			"                       rhost:rport and MTU\n");
		return 1;
	}
	if (argc > 1 && 
	    (!strcmp(argv[argc - 1], "?") || !strncmp(argv[argc - 1], "help", strlen(argv[argc - 1])))) {
		printf( "\n\033[1mshow [arp [<digit>|all]|dump|echo|history|ip [<digit>|all]|ipv6 [<digit>|all]]\033[0m\n"
			"   arp [<digit>|all]   Show arp table for VPC <digit> (default this VPC) or all VPCs\n"
			"   dump [<digit>|all]  Show dump flags for VPC <digit> (default this VPC) or all VPCs\n"
			"   echo                Show the status of the echo flag (see set echo)\n"
			"   history             List the command history\n"
			"   ip [<digit>|all]    Show IPv4 details for VPC <digit> (default this VPC) or all VPCs\n"
			"                       Shows VPC Name, IP address, mask, gateway, DNS, MAC, lport, \n"
			"                       rhost:rport and MTU\n"
			"   ipv6 [<digit>|all]  Show IPv6 details for VPC <digit> (default this VPC) or all VPCs\n"
			"                       Shows VPC Name, IPv6 addresses/mask, gateway, MAC, lport,\n"
			"                       rhost:rport and MTU\n"
			"   version             Show the version information\n");
		return 1;
	}
	
	return 0;
}

int help_version(int argc, char **argv)
{
	return 1;
}

int help_sleep(int argc, char **argv)
{
	printf( "\n\033[1msleep [<seconds>] [<text>]\033[0m, Print <text> and pause execution of script for <seconds>.\n"
		"                            If <seconds>=0 or missing, pause until a key is pressed.\n"
		"                            See \033[1mload <filename>\033[0m\n");
	return 1;
}

int help_help(int argc, char **argv)
{
	printf( "\n\033[1m%s\033[0m, Print help. Use command \033[1m?\033[0m for more help\n", argv[0]);

	return 1;
}

int run_help(int argc, char **argv) 
{
	printf ("\n"
		"?                        Print help. Use command \033[1m?\033[0m for more help\n"
		"<digit>                  Switch to the VPC<digit>. <digit> range 1 to 9\n"
		"arp                      Shortcut for: \033[1mshow arp\033[0m. Show arp table\n"
		"clear [arguments]        Clear IPv4/IPv6, arp/neighbor cache, command history\n"
		"dhcp [-options]          Shortcut for: \033[1mip dhcp [-options]\033[0m. Get IPv4 address via DHCP\n"
		"echo <text>              Display <text> in output\n"
		"help                     Print help. Use command \033[1m?\033[0m for more help\n"
		"history                  Shortcut for: \033[1mshow history\033[0m. List the command history\n"
		"ip [arguments]           Configure VPC's IP settings\n"
		"load <filename>          Load the configuration/script from the file <filename>\n"
		"ping <host> [-options]   Ping the network <host> with ICMP (default) or TCP/UDP\n"
		"quit                     Quit program\n"
		"rlogin [<ip>] <port>     Telnet to <port> at <ip> (def 127.0.0.1) relative to HOST PC\n"
		"save <filename>          Save the configuration to the file <filename>\n"
		"set [arguments]          Set hostname, connection port, dump options and echo on or off\n"
		"show [arguments]         Print the net configuration of VPCs (default). Try \033[1mshow ?\033[0m\n"
		"sleep <seconds>          Pause execution of script for <seconds>. See \033[1mload <filename>\033[0m\n"
		"trace <host> [-options]  Print the path take to network <host>\n"
		"version                  Shortcut for: \033[1mshow version\033[0m\n");
	return 1;			
}

/* end of file */
