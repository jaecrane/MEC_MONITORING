#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

///////////////////////////////////////////////////
// Zynq Ultrascale+ ZCU102 PS System Monitoring  //
///////////////////////////////////////////////////
/* Quard-core Cortex-A53 Full Power Domain (FPD) */
//Temperature
#define zcu102_cur_temp_FPD_addr  0xFFA50A14
#define zcu102_max_temp_FPD_addr  0xFFA50A94
#define zcu102_min_temp_FPD_addr  0xFFA50AB4
//Voltage
#define zcu102_cur_volt_FPD_addr  0xFFA50808
#define zcu102_max_volt_FPD_addr  0xFFA50888
#define zcu102_min_volt_FPD_addr  0xFFA50898

/* Dual-core Cortex-R5 Low Power Domain (LPD) */
//Temperature
#define zcu102_cur_temp_LPD_addr  0xFFA50800
#define zcu102_max_temp_LPD_addr  0xFFA50880
#define zcu102_min_temp_LPD_addr  0xFFA50890
//Voltage
#define zcu102_cur_volt_LPD_addr  0xFFA50804
#define zcu102_max_volt_LPD_addr  0xFFA50884
#define zcu102_min_volt_LPD_addr  0xFFA50894

/* DDR */
//Temperature
//Voltage
#define zcu102_cur_volt_DDR_addr  0xFFA50834
#define zcu102_max_volt_DDR_addr  0xFFA508A0
#define zcu102_min_volt_DDR_addr  0xFFA508B0

/* Battery */
#define zcu102_battery_addr       0xFFA5006C
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//          Zynq ZU9 PS System Monitoring        //
///////////////////////////////////////////////////
/* Cortex A9*/


float calcul_10_bit_adc_t(unsigned int position);
float calcul_10_bit_adc_v(unsigned int position);
unsigned int read_aws_reg (off_t position);

int main(int argc, char *argv[]) {
/*
 if (argc < 2) {
  printf("Usage: %s <> <offset>\n", argv[0]);
  return 0;
 }
*/
// off_t cur_temp_FPD_a = (off_t)zcu102_cur_temp_FPD_addr;
	float cur_temp_FPD = calcul_10_bit_adc_t(read_aws_reg((off_t)zcu102_cur_temp_FPD_addr));
	float max_temp_FPD = calcul_10_bit_adc_t(read_aws_reg((off_t)zcu102_max_temp_FPD_addr));
	float min_temp_FPD = calcul_10_bit_adc_t(read_aws_reg((off_t)zcu102_min_temp_FPD_addr));

 	float cur_volt_FPD = calcul_10_bit_adc_v(read_aws_reg((off_t)zcu102_cur_volt_FPD_addr));
 	float max_volt_FPD = calcul_10_bit_adc_v(read_aws_reg((off_t)zcu102_max_volt_FPD_addr));
 	float min_volt_FPD = calcul_10_bit_adc_v(read_aws_reg((off_t)zcu102_min_volt_FPD_addr));
 	float battery      = calcul_10_bit_adc_v(read_aws_reg((off_t)zcu102_battery_addr));
 	/*printf("Battery:%f\n",	battery);
	printf("Thermal:%f\n", cur_temp_FPD);
	printf("Thermal_MIN:%f\n", min_temp_FPD);
	printf("Thermal_MAX:%f\n", max_temp_FPD);
	printf("Voltage:%f\n", cur_volt_FPD);
	printf("VoltageMIN:%f\n", min_volt_FPD);
	printf("VoltageMAX:%f\n", max_volt_FPD);*/
	
	printf("Battery:%f:Thermal:%f:%f:%f:Voltage:%f:%f:%f:\n",
		battery, cur_temp_FPD, min_temp_FPD, max_temp_FPD, cur_volt_FPD, min_volt_FPD, max_volt_FPD);
	return 0;
}

unsigned int read_aws_reg(off_t offset)
{
 // Truncate offset to a multiple of the page size, or mmap will fail.
 size_t pagesize = sysconf(_SC_PAGE_SIZE);
 off_t page_base = (offset / pagesize) * pagesize;
 off_t page_offset = offset - page_base;
 
 int fd = open("/dev/mem", O_SYNC);
 unsigned char *mem = mmap(NULL, page_offset + 2, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, page_base);
 if (mem == MAP_FAILED) {
  perror("Can't map memory");
  return -1;
 }
 //Read ADC value of [15:6]
 unsigned int value = (4 * (int)mem[page_offset + 1]) + ((int)mem[page_offset] / 64);
 
 return value;
}

float calcul_10_bit_adc_t(unsigned int position)
{
 float Status_cal = (float)position;
 Status_cal *= 502.9098;
 Status_cal /= 1024;
 Status_cal -= 273.8195;
 return Status_cal;
}

float calcul_10_bit_adc_v(unsigned int position)
{
 float Status_cal = (float)position;
 Status_cal *= 3;
 Status_cal /= 1024;
 return Status_cal;
}
