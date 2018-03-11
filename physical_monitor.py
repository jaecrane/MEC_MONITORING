import subprocess
import re
import psutil

#cpufreq = subprocess.check_output ('cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq', shell=True)
#cpufreq = float(cpufreq)
#cpufreq = cpufreq/1000
#cpumaxfreq = subprocess.check_output ('cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq', shell=True)
#cpumaxfreq = float(cpumaxfreq)
#cpumaxfreq = cpumaxfreq/1000
#cpuminfreq = subprocess.check_output ('cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq', shell=True)
#cpuminfreq = float(cpuminfreq)
#cpuminfreq = cpuminfreq/1000

#chipsensor = subprocess.check_output ('./a.out', shell=True)
#sen = str(chipsensor)
#sen2 = sen.split(':');
#print ('current{}'.format(cpu_freq_info[0]))
#print ('CPU Frequency (Mhz): {} ({}~{})'.format(cpufreq,cpuminfreq,cpumaxfreq))
print ('CPU Utilization (%): {} '.format(psutil.cpu_percent(interval=1)))
#print ('CPU Temperature (C): {} ({}~{})'.format(sen2[3],sen2[4],sen2[5]))
#print ('CPU Voltage     (V): {} ({}~{})'.format(sen2[7],sen2[8],sen2[9]))
print ('RAM Utilization (%): {} '.format(psutil.virtual_memory()[2]))
print ('Network Rcv&Snd (B): Send({}) Receive({})'.format(psutil.net_io_counters()[0],psutil.net_io_counters()[1]))
#print ('Battery Measure (V): {} '.format(sen2[1]))
