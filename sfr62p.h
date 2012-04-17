/****************************************************************************
*																			*
*	file name	: definition of M16C/62P's SFR								*
*																			*
*	Copyright	: MITSUBISHI ELECTRIC CORPORATION							*
*																			*
*	Version		: 1.00	( 2002- 4- ) Initial								*
*****************************************************************************/
/*
  note:
	This data is a freeware that SFR for M16C/62P groups is described.
	Mitsubishi Electric Corporation assumes no responsibility for any damage
	that occurred by this data.
*/
/********************************************************
*	declare SFR addresses								*
********************************************************/
#ifndef SFR62P_H
#define SFR62P_H

#pragma ADDRESS		pm0_addr	0004H			/* Processor mode register 0 */

#pragma ADDRESS		pm1_addr	0005H			/* Processor mode register 1 */

#pragma ADDRESS		cm0_addr	0006H			/* System clock control register 0 */

#pragma ADDRESS		cm1_addr	0007H			/* System clock control register 1 */

#pragma ADDRESS		csr_addr	0008H			/* Chip select control register */

#pragma ADDRESS		aier_addr	0009H			/* Address match interrupt enable register */

#pragma ADDRESS		prcr_addr	000aH			/* Protect register */

#pragma ADDRESS		dbr_addr	000bH			/* Data bank register */

#pragma ADDRESS		cm2_addr	000cH			/* Oscillation stop detection register */

#pragma ADDRESS		cm3_addr	000dH			/* Ring mode register */

#pragma ADDRESS		wdts_addr	000eH			/* Watchdog timer start register */

#pragma ADDRESS		wdc_addr	000fH			/* Watchdog timer control register */

#pragma ADDRESS		rmad0_addr	0010H			/* Address match interrupt register 0 */

#pragma ADDRESS		rmad1_addr	0014H			/* Address match interrupt register 1 */

#pragma ADDRESS		cse_addr	001bH			/* Chip select expansion control register */

#pragma ADDRESS		plc0_addr	001cH			/* PLC control register 0 */

#pragma ADDRESS		pm2_addr	001eH			/* Processor mode register 2 */

#pragma ADDRESS		sar0_addr	0020H			/* DMA0 source pointer */

#pragma ADDRESS		dar0_addr	0024H			/* DMA0 destination pointer */

#pragma ADDRESS		tcr0_addr	0028H			/* DMA0 transfer counter */

#pragma ADDRESS		dm0con_addr 002cH			/* DMA0 control register */

#pragma ADDRESS		sar1_addr	0030H			/* DMA1 source pointer */

#pragma ADDRESS		dar1_addr	0034H			/* DMA1 destination pointer */

#pragma ADDRESS		tcr1_addr	0038H			/* DMA1 transfer counter */

#pragma ADDRESS		dm1con_addr 003cH			/* DMA1 control register */

#pragma ADDRESS		int3ic_addr 0044H			/* INT3~ interrupt control register */

#pragma ADDRESS		tb5ic_addr	0045H			/* Timer B5 interrupt control register */

#pragma ADDRESS		tb4ic_addr	0046H			/* Timer B4 interrupt control register */

#pragma ADDRESS		tb3ic_addr	0047H			/* Timer B3 interrupt control register */

#pragma ADDRESS		s4ic_addr	0048H			/* SI/O4 interrupt control register */

#pragma ADDRESS		s3ic_addr	0049H			/* SI/O3 interrupt control register */

#pragma ADDRESS		int5ic_addr 0048H			/* INT5~ interrupt control register */

#pragma ADDRESS		int4ic_addr 0049H			/* INT4~ interrupt control register */

#pragma ADDRESS		bcnic_addr	004aH			/* Bus collision detection interrupt control register */

#pragma ADDRESS		dm0ic_addr	004bH			/* DMA0 interrupt control register */

#pragma ADDRESS		dm1ic_addr	004cH			/* DMA1 interrupt control register */

#pragma ADDRESS		kupic_addr	004dH			/* Key input interrupt control register */

#pragma ADDRESS		adic_addr	004eH			/* A-D conversion interrupt control register */

#pragma ADDRESS		s2tic_addr	004fH			/* UART2 transmit interrupt control register */

#pragma ADDRESS		s2ric_addr	0050H			/* UART2 receive interrupt control register */

#pragma ADDRESS		s0tic_addr	0051H			/* UART0 transmit interrupt control register */

#pragma ADDRESS		s0ric_addr	0052H			/* UART0 receive interrupt control register */

#pragma ADDRESS		s1tic_addr	0053H			/* UART1 transmit interrupt control register */

#pragma ADDRESS		s1ric_addr	0054H			/* UART1 receive interrupt control register */

#pragma ADDRESS		ta0ic_addr	0055H			/* Timer A0 interrupt control register */

#pragma ADDRESS		ta1ic_addr	0056H			/* Timer A1 interrupt control register */

#pragma ADDRESS		ta2ic_addr	0057H			/* Timer A2 interrupt control register */

#pragma ADDRESS		ta3ic_addr	0058H			/* Timer A3 interrupt control register */

#pragma ADDRESS		ta4ic_addr	0059H			/* Timer A4 interrupt control register */

#pragma ADDRESS		tb0ic_addr	005aH			/* Timer B0 interrupt control register */

#pragma ADDRESS		tb1ic_addr	005bH			/* Timer B1 interrupt control register */

#pragma ADDRESS		tb2ic_addr	005cH			/* Timer B2 interrupt control register */

#pragma ADDRESS		int0ic_addr 005dH			/* INT0~ interrupt control register */

#pragma ADDRESS		int1ic_addr 005eH			/* INT1~ interrupt control register */

#pragma ADDRESS		int2ic_addr 005fH			/* INT2~ interrupt control register */

#pragma ADDRESS		fmr1_addr	01b5H			/* Flash memory control register 1 */

#pragma ADDRESS		fmr0_addr	01b7H			/* Flash memory control register 0 */

#pragma ADDRESS		rmad2_addr	01b8H			/* Address match interrupt register 2 */

#pragma ADDRESS		aier2_addr	01bbH			/* Address match interrupt enable register 2 */

#pragma ADDRESS		rmad3_addr	01bcH			/* Address match interrupt register 3 */

#pragma ADDRESS		pclkr_addr	025eH			/* Peripheral clock select register */

#pragma ADDRESS		tbsr_addr	0340H			/* Timer B3,4,5 count start flag */

#pragma ADDRESS		ta11_addr	0342H			/* Timer A1-1 register */

#pragma ADDRESS		ta21_addr	0344H			/* Timer A2-1 register */

#pragma ADDRESS		ta41_addr	0346H			/* Timer A4-1 register */

#pragma ADDRESS		invc0_addr	0348H			/* Three-phase PWM control regester 0 */

#pragma ADDRESS		invc1_addr	0349H			/* Three-phase PWM control register 1 */

#pragma ADDRESS		idb0_addr	034aH			/* Three-phase output buffer register 0 */

#pragma ADDRESS		idb1_addr	034bH			/* Three-phase output buffer register 1 */

#pragma ADDRESS		dtt_addr	034cH			/* Dead time timer */

#pragma ADDRESS		ictb2_addr	034dH			/* Timer B2 interrupt occurrences frequency set counter */

#pragma ADDRESS		tb3_addr	0350H			/* Timer B3 register */

#pragma ADDRESS		tb4_addr	0352H			/* Timer B4 register */

#pragma ADDRESS		tb5_addr	0354H			/* Timer B5 register */

#pragma ADDRESS		tb3mr_addr	035bH			/* Timer B3 mode register */

#pragma ADDRESS		tb4mr_addr	035cH			/* Timer B4 mode register */

#pragma ADDRESS		tb5mr_addr	035dH			/* Timer B5 mode register */

#pragma ADDRESS		ifsr2a_addr	035eH			/* Interrupt request cause select register 2 */

#pragma ADDRESS		ifsr_addr	035fH			/* Interrupt request cause select register */

#pragma ADDRESS		s3trr_addr	0360H			/* SI/O3 transmit/receive register */

#pragma ADDRESS		s3c_addr	0362H			/* SI/O3 control register */

#pragma ADDRESS		s3brg_addr	0363H			/* SI/O3 bit rate generator */

#pragma ADDRESS		s4trr_addr	0364H			/* SI/O4 transmit/receive register */

#pragma ADDRESS		s4c_addr	0366H			/* SI/O4 control register */

#pragma ADDRESS		s4brg_addr	0367H			/* SI/O4 bit rate generator */

#pragma ADDRESS		u0smr4_addr	036cH			/* UART0 special mode register 4 */

#pragma ADDRESS		u0smr3_addr	036dH			/* UART0 special mode register 3 */

#pragma ADDRESS		u0smr2_addr	036eH			/* UART0 special mode register 2 */

#pragma ADDRESS		u0smr_addr	036fH			/* UART0 special mode register */

#pragma ADDRESS		u1smr4_addr	0370H			/* UART1 special mode register 4 */

#pragma ADDRESS		u1smr3_addr	0371H			/* UART1 special mode register 3 */

#pragma ADDRESS		u1smr2_addr	0372H			/* UART1 special mode register 2 */

#pragma ADDRESS		u1smr_addr	0373H			/* UART1 special mode register */

#pragma ADDRESS		u2smr4_addr	0374H			/* UART2 special mode register 4 */

#pragma ADDRESS		u2smr3_addr 0375H			/* UART2 special mode register 3 */

#pragma ADDRESS		u2smr2_addr 0376H			/* UART2 special mode register 2 */

#pragma ADDRESS		u2smr_addr	0377H			/* UART2 special mode register */

#pragma ADDRESS		u2mr_addr	0378H			/* UART2 transmit/receive mode register */

#pragma ADDRESS		u2brg_addr	0379H			/* UART2 bit rate generator */

#pragma ADDRESS		u2tb_addr	037aH			/* UART2 transmit buffer register */

#pragma ADDRESS		u2c0_addr	037cH			/* UART2 transmit/receive control register 0 */

#pragma ADDRESS		u2c1_addr	037dH			/* UART2 transmit/receive control register 1 */

#pragma ADDRESS		u2rb_addr	037eH			/* UART2 receive buffer register */

#pragma ADDRESS		tabsr_addr	0380H			/* Count start flag */

#pragma ADDRESS		cpsrf_addr	0381H			/* Clock prescaler reset flag */

#pragma ADDRESS		onsf_addr	0382H			/* One-shot start flag */

#pragma ADDRESS		trgsr_addr	0383H			/* Trigger select register */

#pragma ADDRESS		udf_addr	0384H			/* Up/down flag */

#pragma ADDRESS		ta0_addr	0386H			/* Timer A0 register */

#pragma ADDRESS		ta1_addr	0388H			/* Timer A1 register */

#pragma ADDRESS		ta2_addr	038aH			/* Timer A2 register */

#pragma ADDRESS		ta3_addr	038cH			/* Timer A3 register */

#pragma ADDRESS		ta4_addr	038eH			/* Timer A4 register */

#pragma ADDRESS		tb0_addr	0390H			/* Timer B0 register */

#pragma ADDRESS		tb1_addr	0392H			/* Timer B1 register */

#pragma ADDRESS		tb2_addr	0394H			/* Timer B2 register */

#pragma ADDRESS		ta0mr_addr	0396H			/* Timer A0 mode register */

#pragma ADDRESS		ta1mr_addr	0397H			/* Timer A1 mode register */

#pragma ADDRESS		ta2mr_addr	0398H			/* Timer A2 mode register */

#pragma ADDRESS		ta3mr_addr	0399H			/* Timer A3 mode register */

#pragma ADDRESS		ta4mr_addr	039aH			/* Timer A4 mode register */

#pragma ADDRESS		tb0mr_addr	039bH			/* Timer B0 mode register */

#pragma ADDRESS		tb1mr_addr	039cH			/* Timer B1 mode register */

#pragma ADDRESS		tb2mr_addr	039dH			/* Timer B2 mode register */

#pragma ADDRESS		tb2sc_addr	039eH			/* Timer B2 special mode register */

#pragma ADDRESS		u0mr_addr	03a0H			/* UART0 transmit/receive mode register */

#pragma ADDRESS		u0brg_addr	03a1H			/* UART0 bit rate generator */

#pragma ADDRESS		u0tb_addr	03a2H			/* UART0 transmit buffer register */

#pragma ADDRESS		u0c0_addr	03a4H			/* UART0 transmit/receive control register 0 */

#pragma ADDRESS		u0c1_addr	03a5H			/* UART0 transmit/receive control register 1 */

#pragma ADDRESS		u0rb_addr	03a6H			/* UART0 receive buffer register */

#pragma ADDRESS		u1mr_addr	03a8H			/* UART1 transmit/receive mode register */

#pragma ADDRESS		u1brg_addr	03a9H			/* UART1 bit rate generator */

#pragma ADDRESS		u1tb_addr	03aaH			/* UART1 transmit buffer register */

#pragma ADDRESS		u1c0_addr	03acH			/* UART1 transmit/receive control register 0 */

#pragma ADDRESS		u1c1_addr	03adH			/* UART1 transmit/receive control register 1 */

#pragma ADDRESS		u1rb_addr	03aeH			/* UART1 receive buffer register */

#pragma ADDRESS		ucon_addr	03b0H			/* UART transmit/receive control register 2 */

#pragma ADDRESS		fidr_addr	03b4H			/* Flash identification register */

#pragma ADDRESS		dm0sl_addr	03b8H			/* DMA0 cause select register */

#pragma ADDRESS		dm1sl_addr	03baH			/* DMA1 cause select register */

#pragma ADDRESS		crcd_addr	03bcH			/* CRC data register */

#pragma ADDRESS		crcin_addr	03beH			/* CRC input register */

#pragma ADDRESS		ad0_addr	03c0H			/* A-D register 0 */

#pragma ADDRESS		ad1_addr	03c2H			/* A-D register 1 */

#pragma ADDRESS		ad2_addr	03c4H			/* A-D register 2 */

#pragma ADDRESS		ad3_addr	03c6H			/* A-D register 3 */

#pragma ADDRESS		ad4_addr	03c8H			/* A-D register 4 */

#pragma ADDRESS		ad5_addr	03caH			/* A-D register 5 */

#pragma ADDRESS		ad6_addr	03ccH			/* A-D register 6 */

#pragma ADDRESS		ad7_addr	03ceH			/* A-D register 7 */

#pragma ADDRESS		adcon2_addr 03d4H			/* A-D control register 2 */

#pragma ADDRESS		adcon0_addr 03d6H			/* A-D control register 0 */

#pragma ADDRESS		adcon1_addr 03d7H			/* A-D control register 1 */

#pragma ADDRESS		da0_addr	03d8H			/* D-A register 0 */

#pragma ADDRESS		da1_addr	03daH			/* D-A register 1 */

#pragma ADDRESS		dacon_addr	03dcH			/* D-A control register */

#pragma ADDRESS		pc14_addr	03deH			/* Port P14 control register */

#pragma ADDRESS		pur3_addr	03dfH			/* Pull-up control register 3 */

#pragma ADDRESS		p0_addr		03e0H			/* Port P0 register */

#pragma ADDRESS		p1_addr		03e1H			/* Port P1 register */

#pragma ADDRESS		pd0_addr	03e2H			/* Port P0 direction register */

#pragma ADDRESS		pd1_addr	03e3H			/* Port P1 direction register */

#pragma ADDRESS		p2_addr		03e4H			/* Port P2 register */

#pragma ADDRESS		p3_addr		03e5H			/* Port P3 register */

#pragma ADDRESS		pd2_addr	03e6H			/* Port P2 direction register */

#pragma ADDRESS		pd3_addr	03e7H			/* Port P3 direction register */

#pragma ADDRESS		p4_addr		03e8H			/* Port P4 register */

#pragma ADDRESS		p5_addr		03e9H			/* Port P5 register */

#pragma ADDRESS		pd4_addr	03eaH			/* Port P4 direction register */

#pragma ADDRESS		pd5_addr	03ebH			/* Port P5 direction register */

#pragma ADDRESS		p6_addr		03ecH			/* Port P6 register */

#pragma ADDRESS		p7_addr		03edH			/* Port P7 register */

#pragma ADDRESS		pd6_addr	03eeH			/* Port P6 direction register */

#pragma ADDRESS		pd7_addr	03efH			/* Port P7 direction register */

#pragma ADDRESS		p8_addr		03f0H			/* Port P8 register */

#pragma ADDRESS		p9_addr		03f1H			/* Port P9 register */

#pragma ADDRESS		pd8_addr	03f2H			/* Port P8 direction register */

#pragma ADDRESS		pd9_addr	03f3H			/* Port P9 direction register */

#pragma ADDRESS		p10_addr	03f4H			/* Port P10 register */

#pragma ADDRESS		p11_addr	03f5H			/* Port P11 register */

#pragma ADDRESS		pd10_addr	03f6H			/* Port P10 direction register */

#pragma ADDRESS		pd11_addr	03f7H			/* Port P11 direction register */

#pragma ADDRESS		p12_addr	03f8H			/* Port P12 register */

#pragma ADDRESS		p13_addr	03f9H			/* Port P13 register */

#pragma ADDRESS		pd12_addr	03faH			/* Port P12 direction register */

#pragma ADDRESS		pd13_addr	03fbH			/* Port P13 direction register */

#pragma ADDRESS		pur0_addr	03fcH			/* Pull-up control register 0 */

#pragma ADDRESS		pur1_addr	03fdH			/* Pull-up control register 1 */

#pragma ADDRESS		pur2_addr	03feH			/* Pull-up control register 2 */

#pragma ADDRESS		pcr_addr	03ffH			/* Port control register */

/********************************************************
*	declare	 SFR char									*
********************************************************/
unsigned char	da0_addr;						/* D-A register 0 */
#define		da0		da0_addr

unsigned char	da1_addr;						/* D-A register 1 */
#define		da1		da1_addr

/*--------------------------------------------------------
	Up/down flag ; Use "MOV" instruction when writing to this register.
--------------------------------------------------------*/
unsigned char	udf_addr;
#define		udf		udf_addr

/********************************************************
*	declare	 SFR short									*
********************************************************/
/*--------------------------------------------------------
	Timer registers : Read and write data in 16-bit units.
--------------------------------------------------------*/
unsigned short	 ta11_addr;						/* Timer A1-1 register */
#define		ta11	ta11_addr

unsigned short	 ta21_addr;						/* Timer A2-1 register */
#define		ta21	ta21_addr

unsigned short	 ta41_addr;						/* Timer A4-1 register */
#define		ta41	ta41_addr

unsigned short	 tb3_addr;						/* Timer B3 register */
#define		tb3		tb3_addr

unsigned short	 tb4_addr;						/* Timer B4 register */
#define		tb4		tb4_addr

unsigned short	 tb5_addr;						/* Timer B5 register */
#define		tb5		tb5_addr

unsigned short	 ta0_addr;						/* Timer A0 register */
#define		ta0		ta0_addr

unsigned short	 ta1_addr;						/* Timer A1 register */
#define		ta1		ta1_addr

unsigned short	 ta2_addr;						/* Timer A2 register */
#define		ta2		ta2_addr

unsigned short	 ta3_addr;						/* Timer A3 register */
#define		ta3		ta3_addr

unsigned short	 ta4_addr;						/* Timer A4 register */
#define		ta4		ta4_addr

unsigned short	 tb0_addr;						/* Timer B0 register */
#define		tb0		tb0_addr

unsigned short	 tb1_addr;						/* Timer B1 register */
#define		tb1		tb1_addr

unsigned short	 tb2_addr;						/* Timer B2 register */
#define		tb2		tb2_addr

/********************************************************
*	declare SFR bit										*
********************************************************/
struct bit_def {
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
};
union byte_def{
	struct bit_def bit;
	char	byte;
};

/*------------------------------------------------------
	Processor mode register 0
------------------------------------------------------*/
union byte_def pm0_addr;
#define		pm0				pm0_addr.byte

#define		pm00			pm0_addr.bit.b0		/* Processor mode bit */
#define		pm01			pm0_addr.bit.b1		/* Processor mode bit */
#define		pm02			pm0_addr.bit.b2		/* R/W mode select bit */
#define		pm03			pm0_addr.bit.b3		/* Software reset bit */
#define		pm04			pm0_addr.bit.b4		/* Multiplexed bus space select bit */
#define		pm05			pm0_addr.bit.b5		/* Multiplexed bus space select bit */
#define		pm06			pm0_addr.bit.b6		/* Port P4_0 to P4_3 function select bit */
#define		pm07			pm0_addr.bit.b7		/* BCLK output disable bit */

/*------------------------------------------------------
	Processor mode register 1
------------------------------------------------------*/
union byte_def pm1_addr;
#define		pm1				pm1_addr.byte

#define		pm10			pm1_addr.bit.b0		/* CS2 area switching bit */
#define		pm11			pm1_addr.bit.b1		/* Port P3_4 to P3_7 function select bit */
#define		pm12			pm1_addr.bit.b2		/* Watch dog timer function select bit */
#define		pm13			pm1_addr.bit.b3		/* Intermal reserved area expansion bit */
#define		pm14			pm1_addr.bit.b4		/* Memory area expansion bit */
#define		pm15			pm1_addr.bit.b5		/* Memory area expansion bit */
#define		pm17			pm1_addr.bit.b7		/* Wait bit */

/*------------------------------------------------------
	System clock control register 0
------------------------------------------------------*/
union byte_def cm0_addr;
#define		cm0				cm0_addr.byte

#define		cm00			cm0_addr.bit.b0		/* Clock output function select bit */
#define		cm01			cm0_addr.bit.b1		/* Clock output function select bit */
#define		cm02			cm0_addr.bit.b2		/* WAIT peripheral function clock stop bit */
#define 	cm03			cm0_addr.bit.b3 	/* Xcin-Xcout drive capacity select bit */
#define		cm04			cm0_addr.bit.b4		/* Port Xc select bit */
#define		cm05			cm0_addr.bit.b5		/* Main clock stop bit */
#define		cm06			cm0_addr.bit.b6		/* Main clock division select bit 0 */
#define		cm07			cm0_addr.bit.b7		/* System clock select bit */

/*------------------------------------------------------
	System clock control register 1
------------------------------------------------------*/
union byte_def cm1_addr;
#define		cm1				cm1_addr.byte

#define		cm10			cm1_addr.bit.b0		/* All clock stop control bit */
#define		cm11			cm1_addr.bit.b1		/* System clock select bit */
#define		cm15			cm1_addr.bit.b5		/* Xin-Xout drive capacity select bit */
#define		cm16			cm1_addr.bit.b6		/* Main clock division select bit 1 */
#define		cm17			cm1_addr.bit.b7		/* Main clock division select bit 1 */

/*------------------------------------------------------
	Chip select control register
------------------------------------------------------*/
union byte_def csr_addr;
#define		csr				csr_addr.byte

#define		cs0				csr_addr.bit.b0		/* CS0~ output enable bit */
#define		cs1				csr_addr.bit.b1		/* CS1~ output enable bit */
#define		cs2				csr_addr.bit.b2		/* CS2~ output enable bit */
#define		cs3				csr_addr.bit.b3		/* CS3~ output enable bit */
#define		cs0w			csr_addr.bit.b4		/* CS0~ wait bit */
#define		cs1w			csr_addr.bit.b5		/* CS1~ wait bit */
#define		cs2w			csr_addr.bit.b6		/* CS2~ wait bit */
#define		cs3w			csr_addr.bit.b7		/* CS3~ wait bit */

/*------------------------------------------------------
	Address match interrupt enable register
------------------------------------------------------*/
union byte_def aier_addr;
#define		aier			aier_addr.byte

#define		aier0			aier_addr.bit.b0	/* Address match interrupt 0 enable bit */
#define		aier1			aier_addr.bit.b1	/* Address match interrupt 1 enable bit */

/*------------------------------------------------------
	Protect register
------------------------------------------------------*/
union byte_def prcr_addr;
#define		prcr			prcr_addr.byte

#define		prc0			prcr_addr.bit.b0	/* Enable writting to system clock control registers 0 and 1 */
#define		prc1			prcr_addr.bit.b1	/* Enable writting to processor mode registers 0 and 1 */
#define		prc2			prcr_addr.bit.b2	/* Enable writting to port P9 direction register and SI/Oi control register(i=3,4) */

/*------------------------------------------------------
	Data bank register
------------------------------------------------------*/
union byte_def dbr_addr;
#define		dbr				dbr_addr.byte

#define		ofs				dbr_addr.bit.b2		/* Offset bit */
#define		bsr0			dbr_addr.bit.b3		/* Bank select bit 0 */
#define		bsr1			dbr_addr.bit.b4		/* Bank select bit 1 */
#define		bsr2			dbr_addr.bit.b5		/* Bank select bit 2 */

/*------------------------------------------------------
	Oscillation stop detection register
------------------------------------------------------*/
union byte_def cm2_addr;
#define		cm2				cm2_addr.byte

#define		cm20			cm2_addr.bit.b0		/* Oscillation stop detection bit */
#define		cm21			cm2_addr.bit.b1		/* Main clock switch bit */
#define		cm22			cm2_addr.bit.b2		/* Oscillation stop detection status */
#define		cm23			cm2_addr.bit.b3		/* Clock monitor bit */
#define		cm27			cm2_addr.bit.b7		/* Operation select bit(when an oscillation stop is detected) */

/*------------------------------------------------------
	Watchdog timer start register
------------------------------------------------------*/
union byte_def wdts_addr;
#define		wdts			wdts_addr.byte

/*------------------------------------------------------
	Watchdog timer control register
------------------------------------------------------*/
union byte_def wdc_addr;
#define		wdc				wdc_addr.byte

#define		wdc7			wdc_addr.bit.b7		/* Prescaler select bit */

/*------------------------------------------------------
	Chip select expansion control register
------------------------------------------------------*/
union byte_def cse_addr;
#define		cse				cse_addr.byte

#define		cse00w			cse_addr.bit.b0		/* CS0~ wait expansion bit */
#define		cse01w			cse_addr.bit.b1		/* CS0~ wait expansion bit */
#define		cse10w			cse_addr.bit.b2		/* CS1~ wait expansion bit */
#define		cse11w			cse_addr.bit.b3		/* CS1~ wait expansion bit */
#define		cse20w			cse_addr.bit.b4		/* CS2~ wait expansion bit */
#define		cse21w			cse_addr.bit.b5		/* CS2~ wait expansion bit */
#define		cse30w			cse_addr.bit.b6		/* CS3~ wait expansion bit */
#define		cse31w			cse_addr.bit.b7		/* CS3~ wait expansion bit */

/*------------------------------------------------------
	PLL control register 0
------------------------------------------------------*/
union byte_def plc0_addr;
#define		plc0			plc0_addr.byte

#define		plc00			plc0_addr.bit.b0	/* Programmable counter select bit */
#define		plc01			plc0_addr.bit.b1	/* Programmable counter select bit */
#define		plc02			plc0_addr.bit.b2	/* Programmable counter select bit */
#define		plc06			plc0_addr.bit.b6	/* External low-pass filter connecting bit */
#define		plc07			plc0_addr.bit.b7	/* Operation enable bit */

/*------------------------------------------------------
	Processor mode register 2
------------------------------------------------------*/
union byte_def pm2_addr;
#define		pm2				pm2_addr.byte

#define		pm20			pm2_addr.bit.b0		/* Specifying wait when accessing SFR at PLL operation */

/*------------------------------------------------------
	 DMA0 control register
------------------------------------------------------*/
union byte_def dm0con_addr;
#define		dm0con			dm0con_addr.byte

#define		dmbit_dm0con	dm0con_addr.bit.b0	/* Transfer unit bit select bit */
#define		dmasl_dm0con	dm0con_addr.bit.b1	/* Repeat transfer mode select bit */
#define		dmas_dm0con		dm0con_addr.bit.b2	/* DMA request bit */
#define		dmae_dm0con		dm0con_addr.bit.b3	/* DMA enable bit */
#define		dsd_dm0con		dm0con_addr.bit.b4	/* Source address direction select bit */
#define		dad_dm0con		dm0con_addr.bit.b5	/* Destination address direction select bit */

/*------------------------------------------------------
	 DMA1 control register
------------------------------------------------------*/
union byte_def	dm1con_addr;
#define		dm1con			dm1con_addr.byte

#define		dmbit_dm1con	dm1con_addr.bit.b0	/* Transfer unit bit select bit */
#define		dmasl_dm1con	dm1con_addr.bit.b1	/* Repeat transfer mode select bit */
#define		dmas_dm1con		dm1con_addr.bit.b2	/* DMA request bit */
#define		dmae_dm1con		dm1con_addr.bit.b3	/* DMA enable bit */
#define		dsd_dm1con		dm1con_addr.bit.b4	/* Source address direction select bit */
#define		dad_dm1con		dm1con_addr.bit.b5	/* Destination address direction select bit */

/*------------------------------------------------------
	INT3 interrupt control register
------------------------------------------------------*/
union byte_def int3ic_addr;
#define		int3ic			int3ic_addr.byte

#define		ilvl0_int3ic	int3ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_int3ic	int3ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_int3ic	int3ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_int3ic		int3ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_int3ic		int3ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	Timer B5 interrupt control register
------------------------------------------------------*/
union byte_def tb5ic_addr;
#define		tb5ic			tb5ic_addr.byte

#define		ilvl0_tb5ic		tb5ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_tb5ic		tb5ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_tb5ic		tb5ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_tb5ic		tb5ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer B4 interrupt control register
------------------------------------------------------*/
union byte_def tb4ic_addr;
#define		tb4ic			tb4ic_addr.byte

#define		ilvl0_tb4ic		tb4ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_tb4ic		tb4ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_tb4ic		tb4ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_tb4ic		tb4ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer B3 interrupt control register
------------------------------------------------------*/
union byte_def tb3ic_addr;
#define		tb3ic			tb3ic_addr.byte

#define		ilvl0_tb3ic		tb3ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_tb3ic		tb3ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_tb3ic		tb3ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_tb3ic		tb3ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	SI/O4 interrupt control register
------------------------------------------------------*/
union byte_def s4ic_addr;
#define		s4ic			s4ic_addr.byte

#define		ilvl0_s4ic		s4ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s4ic		s4ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s4ic		s4ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s4ic			s4ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_s4ic		s4ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	SI/O3 interrupt control register
------------------------------------------------------*/
union byte_def s3ic_addr;
#define		s3ic			s3ic_addr.byte

#define		ilvl0_s3ic		s3ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s3ic		s3ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s3ic		s3ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s3ic			s3ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_s3ic		s3ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	INT5 interrupt control register
------------------------------------------------------*/
union byte_def int5ic_addr;
#define		int5ic			int5ic_addr.byte

#define		ilvl0_int5ic	int5ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_int5ic	int5ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_int5ic	int5ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_int5ic		int5ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_int5ic		int5ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	INT4 interrupt control register
------------------------------------------------------*/
union byte_def int4ic_addr;
#define		int4ic			int4ic_addr.byte

#define		ilvl0_int4ic	int4ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_int4ic	int4ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_int4ic	int4ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_int4ic		int4ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_int4ic		int4ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	Bus collision detection interrupt control register
------------------------------------------------------*/
union byte_def bcnic_addr;
#define		bcnic			bcnic_addr.byte

#define		ilvl0_bcnic		bcnic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_bcnic		bcnic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_bcnic		bcnic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_bcnic		bcnic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	DMA0 interrupt control register
------------------------------------------------------*/
union byte_def dm0ic_addr;
#define		dm0ic			dm0ic_addr.byte

#define		ilvl0_dm0ic		dm0ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_dm0ic		dm0ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_dm0ic		dm0ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_dm0ic		dm0ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	DMA1 interrupt control register
------------------------------------------------------*/
union byte_def dm1ic_addr;
#define		dm1ic			dm1ic_addr.byte

#define		ilvl0_dm1ic		dm1ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_dm1ic		dm1ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_dm1ic		dm1ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_dm1ic		dm1ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Key input interrupt control register
------------------------------------------------------*/
union byte_def kupic_addr;
#define		kupic			kupic_addr.byte

#define		ilvl0_kupic		kupic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_kupic		kupic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_kupic		kupic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_kupic		kupic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	A-D conversion interrupt control register
------------------------------------------------------*/
union byte_def adic_addr;
#define		adic			adic_addr.byte

#define		ilvl0_adic		adic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_adic		adic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_adic		adic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_adic			adic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	UART2 transmit interrupt control register
------------------------------------------------------*/
union byte_def s2tic_addr;
#define		s2tic			s2tic_addr.byte

#define		ilvl0_s2tic		s2tic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s2tic		s2tic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s2tic		s2tic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s2tic		s2tic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	UART2 receive interrupt control register
------------------------------------------------------*/
union byte_def s2ric_addr;
#define		s2ric			s2ric_addr.byte

#define		ilvl0_s2ric		s2ric_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s2ric		s2ric_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s2ric		s2ric_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s2ric		s2ric_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	UART0 transmit interrupt control register
------------------------------------------------------*/
union byte_def s0tic_addr;
#define		s0tic			s0tic_addr.byte

#define		ilvl0_s0tic		s0tic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s0tic		s0tic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s0tic		s0tic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s0tic		s0tic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	UART0 receive interrupt control register
------------------------------------------------------*/
union byte_def s0ric_addr;
#define		s0ric			s0ric_addr.byte

#define		ilvl0_s0ric		s0ric_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s0ric		s0ric_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s0ric		s0ric_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s0ric		s0ric_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	UART1 transmit interrupt control register
------------------------------------------------------*/
union byte_def s1tic_addr;
#define		s1tic			s1tic_addr.byte

#define		ilvl0_s1tic		s1tic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s1tic		s1tic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s1tic		s1tic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s1tic		s1tic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	UART1 receive interrupt control register
------------------------------------------------------*/
union byte_def s1ric_addr;
#define		s1ric			s1ric_addr.byte

#define		ilvl0_s1ric		s1ric_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_s1ric		s1ric_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_s1ric		s1ric_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_s1ric		s1ric_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer A0 receive interrupt control register
------------------------------------------------------*/
union byte_def ta0ic_addr;
#define		ta0ic			ta0ic_addr.byte

#define		ilvl0_ta0ic		ta0ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_ta0ic		ta0ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_ta0ic		ta0ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_ta0ic		ta0ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer A1 receive interrupt control register
------------------------------------------------------*/
union byte_def ta1ic_addr;
#define		ta1ic			ta1ic_addr.byte

#define		ilvl0_ta1ic		ta1ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_ta1ic		ta1ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_ta1ic		ta1ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_ta1ic		ta1ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer A2 receive interrupt control register
------------------------------------------------------*/
union byte_def ta2ic_addr;
#define		ta2ic			ta2ic_addr.byte

#define		ilvl0_ta2ic		ta2ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_ta2ic		ta2ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_ta2ic		ta2ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_ta2ic		ta2ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer A3 receive interrupt control register
------------------------------------------------------*/
union byte_def ta3ic_addr;
#define		ta3ic			ta3ic_addr.byte

#define		ilvl0_ta3ic		ta3ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_ta3ic		ta3ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_ta3ic		ta3ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_ta3ic		ta3ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer A4 receive interrupt control register
------------------------------------------------------*/
union byte_def ta4ic_addr;
#define		ta4ic			ta4ic_addr.byte

#define		ilvl0_ta4ic		ta4ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_ta4ic		ta4ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_ta4ic		ta4ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_ta4ic		ta4ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer B0 receive interrupt control register
------------------------------------------------------*/
union byte_def tb0ic_addr;
#define		tb0ic			tb0ic_addr.byte

#define		ilvl0_tb0ic		tb0ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_tb0ic		tb0ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_tb0ic		tb0ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_tb0ic		tb0ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer B1 receive interrupt control register
------------------------------------------------------*/
union byte_def tb1ic_addr;
#define		tb1ic			tb1ic_addr.byte

#define		ilvl0_tb1ic		tb1ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_tb1ic		tb1ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_tb1ic		tb1ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_tb1ic		tb1ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	Timer B2 receive interrupt control register
------------------------------------------------------*/
union byte_def tb2ic_addr;
#define		tb2ic			tb2ic_addr.byte

#define		ilvl0_tb2ic		tb2ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_tb2ic		tb2ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_tb2ic		tb2ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_tb2ic		tb2ic_addr.bit.b3	/* Interrupt request bit */

/*------------------------------------------------------
	INT0 receive interrupt control register
------------------------------------------------------*/
union byte_def int0ic_addr;
#define		int0ic			int0ic_addr.byte

#define		ilvl0_int0ic	int0ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_int0ic	int0ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_int0ic	int0ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_int0ic		int0ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_int0ic		int0ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	INT1 receive interrupt control register
------------------------------------------------------*/
union byte_def int1ic_addr;
#define		int1ic			int1ic_addr.byte

#define		ilvl0_int1ic	int1ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_int1ic	int1ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_int1ic	int1ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_int1ic		int1ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_int1ic		int1ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	INT2 receive interrupt control register
------------------------------------------------------*/
union byte_def int2ic_addr;
#define		int2ic			int2ic_addr.byte

#define		ilvl0_int2ic	int2ic_addr.bit.b0	/* Interrupt priority level select bit */
#define		ilvl1_int2ic	int2ic_addr.bit.b1	/* Interrupt priority level select bit */
#define		ilvl2_int2ic	int2ic_addr.bit.b2	/* Interrupt priority level select bit */
#define		ir_int2ic		int2ic_addr.bit.b3	/* Interrupt request bit */
#define		pol_int2ic		int2ic_addr.bit.b4	/* Polarity select bit */

/*------------------------------------------------------
	Flash memory control register 1 
------------------------------------------------------*/
union byte_def fmr1_addr;
#define		fmr1			fmr1_addr.byte

#define		fmr11			fmr1_addr.bit.b1	/* EW1 mode select bit */
#define		fmr16			fmr1_addr.bit.b6	/* Lock bit status flag */

/*------------------------------------------------------
	 Flash memory control register 0
------------------------------------------------------*/
union byte_def fmr0_addr;
#define		fmr0			fmr0_addr.byte

#define		fmr00			fmr0_addr.bit.b0	/* RY/BY~ status flag */
#define		fmr01			fmr0_addr.bit.b1	/* EW0 mode select bit */
#define		fmr02			fmr0_addr.bit.b2	/* Lock bit disable bit */
#define		fmr03			fmr0_addr.bit.b3	/* Flash memory reset bit */
#define		fmr05			fmr0_addr.bit.b5	/* User ROM area select bit */
#define		fmr06			fmr0_addr.bit.b6	/* Program status flag */
#define		fmr07			fmr0_addr.bit.b7	/* Erase status flag */

/*------------------------------------------------------
	Address match interrupt enable register 2
------------------------------------------------------*/
union byte_def aier2_addr;
#define		aier2			aier2_addr.byte

#define		aier20			aier2_addr.bit.b0	/* Address match interrupt 2 enable bit */
#define		aier21			aier2_addr.bit.b1	/* Address match interrupt 3 enable bit */

/*------------------------------------------------------
	Peripheral clock select register
------------------------------------------------------*/
union byte_def pclkr_addr;
#define		pclkr			pclkr_addr.byte

#define		pclk0			pclkr_addr.bit.b0	/* TimerA,B clock select bit */
#define		pclk1			pclkr_addr.bit.b1	/* SI/O clock select bit */

/*------------------------------------------------------
	Timer B3,4,5 Count start flag
------------------------------------------------------*/
union byte_def tbsr_addr;
#define		tbsr			tbsr_addr.byte

#define		tb3s			tbsr_addr.bit.b5	/* Timer B3 count start flag */
#define		tb4s			tbsr_addr.bit.b6	/* Timer B4 count start flag */
#define		tb5s			tbsr_addr.bit.b7	/* Timer B5 count start flag */

/*------------------------------------------------------
	Three-phase PWM control regester 0 
------------------------------------------------------*/
union byte_def invc0_addr;
#define		invc0			invc0_addr.byte

#define		inv00			invc0_addr.bit.b0	/* Effective interrupt output polarity select bit */
#define		inv01			invc0_addr.bit.b1	/* Effective interrupt output specification bit */
#define		inv02			invc0_addr.bit.b2	/* Mode select bit */
#define		inv03			invc0_addr.bit.b3	/* Output control bit */
#define		inv04			invc0_addr.bit.b4	/* Positive and negative phases concurrent L output disable function enable bit */
#define		inv05			invc0_addr.bit.b5	/* Positive and negative phases concurrent L output detect flag */
#define		inv06			invc0_addr.bit.b6	/* Modulation mode select bit */
#define		inv07			invc0_addr.bit.b7	/* Software trigger bit */

/*------------------------------------------------------
	Three-phase PWM control regester 1
------------------------------------------------------*/
union byte_def invc1_addr;
#define		invc1			invc1_addr.byte

#define		inv10			invc1_addr.bit.b0	/* Timer Ai start trigger signal select bit */
#define		inv11			invc1_addr.bit.b1	/* Timer A1-1,A2-1,A4-1 control bit */
#define		inv12			invc1_addr.bit.b2	/* Dead time timer count source select bit */
#define		inv13			invc1_addr.bit.b3	/* Carrier wave detect flag */
#define		inv14			invc1_addr.bit.b4	/* Output porality control bit */
#define		inv15			invc1_addr.bit.b5	/* Dead time invalid bit */
#define		inv16			invc1_addr.bit.b6	/* Dead time timer trigger select bit */
#define		inv17			invc1_addr.bit.b7	/* Waveform reflect timing select bit */

/*------------------------------------------------------
	Three-phase output buffer register 0
------------------------------------------------------*/
union byte_def idb0_addr;
#define		idb0			idb0_addr.byte

#define		du0				idb0_addr.bit.b0	/* U  phase output buffer 0 */
#define		dub0			idb0_addr.bit.b1	/* U~ phase output buffer 0 */
#define		dv0				idb0_addr.bit.b2	/* V  phase output buffer 0 */
#define		dvb0			idb0_addr.bit.b3	/* V~ phase output buffer 0 */
#define		dw0				idb0_addr.bit.b4	/* W  phase output buffer 0 */
#define		dwb0			idb0_addr.bit.b5	/* W~ phase output buffer 0 */

/*------------------------------------------------------
	Three-phase output buffer register 1
------------------------------------------------------*/
union byte_def idb1_addr;
#define		idb1			idb1_addr.byte

#define		du1				idb1_addr.bit.b0	/* U  phase output buffer 1 */
#define		dub1			idb1_addr.bit.b1	/* U~ phase output buffer 1 */
#define		dv1				idb1_addr.bit.b2	/* V  phase output buffer 1 */
#define		dvb1			idb1_addr.bit.b3	/* V~ phase output buffer 1 */
#define		dw1				idb1_addr.bit.b4	/* W  phase output buffer 1 */
#define		dwb1			idb1_addr.bit.b5	/* W~ phase output buffer 1 */

/*------------------------------------------------------
	 Dead time timer ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
union byte_def dtt_addr;
#define		dtt				dtt_addr.byte

/*------------------------------------------------------------------
	 Timer B2 interrupt occurrences frequency set counter ; Use "MOV" instruction when writing to this register.
-------------------------------------------------------------------*/
union byte_def ictb2_addr;
#define		ictb2			ictb2_addr.byte

/*------------------------------------------------------
	 Timer B3 mode register
------------------------------------------------------*/
union byte_def tb3mr_addr;
#define		tb3mr			tb3mr_addr.byte

#define		tmod0_tb3mr		tb3mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_tb3mr		tb3mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_tb3mr		tb3mr_addr.bit.b2
#define		mr1_tb3mr		tb3mr_addr.bit.b3
#define		mr2_tb3mr		tb3mr_addr.bit.b4
#define		mr3_tb3mr		tb3mr_addr.bit.b5
#define		tck0_tb3mr		tb3mr_addr.bit.b6	/* Count source select bit */
#define		tck1_tb3mr		tb3mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer B4 mode register
------------------------------------------------------*/
union byte_def tb4mr_addr;
#define		tb4mr			tb4mr_addr.byte

#define		tmod0_tb4mr		tb4mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_tb4mr		tb4mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_tb4mr		tb4mr_addr.bit.b2
#define		mr1_tb4mr		tb4mr_addr.bit.b3
#define		mr3_tb4mr		tb4mr_addr.bit.b5
#define		tck0_tb4mr		tb4mr_addr.bit.b6	/* Count source select bit */
#define		tck1_tb4mr		tb4mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer B5 mode register
------------------------------------------------------*/
union byte_def tb5mr_addr;
#define		tb5mr			tb5mr_addr.byte

#define		tmod0_tb5mr		tb5mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_tb5mr		tb5mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_tb5mr		tb5mr_addr.bit.b2
#define		mr1_tb5mr		tb5mr_addr.bit.b3
#define		mr3_tb5mr		tb5mr_addr.bit.b5
#define		tck0_tb5mr		tb5mr_addr.bit.b6	/* Count source select bit */
#define		tck1_tb5mr		tb5mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Interrupt request cause select register 2
------------------------------------------------------*/
union byte_def ifsr2a_addr;
#define		ifsr2a			ifsr2a_addr.byte

#define		ifsr26			ifsr2a_addr.bit.b6	/* Interrupt request cause select bit */
#define		ifsr27			ifsr2a_addr.bit.b7	/* Interrupt request cause select bit */

/*------------------------------------------------------
	 Interrupt request cause select register
------------------------------------------------------*/
union byte_def ifsr_addr;
#define		ifsr			ifsr_addr.byte

#define		ifsr0			ifsr_addr.bit.b0	/* INT0~ interrupt polarity switching bit */
#define		ifsr1			ifsr_addr.bit.b1	/* INT1~ interrupt polarity switching bit */
#define		ifsr2			ifsr_addr.bit.b2	/* INT2~ interrupt polarity switching bit */
#define		ifsr3			ifsr_addr.bit.b3	/* INT3~ interrupt polarity switching bit */
#define		ifsr4			ifsr_addr.bit.b4	/* INT4~ interrupt polarity switching bit */
#define		ifsr5			ifsr_addr.bit.b5	/* INT5~ interrupt polarity switching bit */
#define		ifsr6			ifsr_addr.bit.b6	/* Interrupt request cause select bit */
#define		ifsr7			ifsr_addr.bit.b7	/* Interrupt request cause select bit */

/*------------------------------------------------------
	SI/O3 transmit/receive register
------------------------------------------------------*/
union byte_def s3trr_addr;
#define		s3trr			s3trr_addr.byte

/*------------------------------------------------------
	SI/O3 control register 
------------------------------------------------------*/
union byte_def s3c_addr;
#define		s3c				s3c_addr.byte

#define		sm30			s3c_addr.bit.b0		/* Internal synchronous clock select bit */
#define		sm31			s3c_addr.bit.b1		/* Internal synchronous clock select bit */
#define		sm32			s3c_addr.bit.b2		/* Sout3 output disable bit */
#define		sm33			s3c_addr.bit.b3		/* SI/O3 port select bit */
#define		sm34			s3c_addr.bit.b4		/* CLK polarity select bit */
#define		sm35			s3c_addr.bit.b5		/* Transfer direction select bit */
#define		sm36			s3c_addr.bit.b6		/* Synchronous clock select bit */
#define		sm37			s3c_addr.bit.b7		/* Sout3 initial value set bit */

/*------------------------------------------------------
	SI/O3 bit rate generator ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
union byte_def s3brg_addr;
#define		s3brg			s3brg_addr.byte

/*------------------------------------------------------
	SI/O4 transmit/receive register
------------------------------------------------------*/
union byte_def s4trr_addr;
#define		s4trr			s4trr_addr.byte

/*------------------------------------------------------
	SI/O4 control register 
------------------------------------------------------*/
union byte_def s4c_addr;
#define		s4c				s4c_addr.byte

#define		sm40			s4c_addr.bit.b0		/* Internal synchronous clock select bit */
#define		sm41			s4c_addr.bit.b1		/* Internal synchronous clock select bit */
#define		sm42			s4c_addr.bit.b2		/* Sout4 output disable bit */
#define		sm43			s4c_addr.bit.b3		/* SI/O4 port select bit */
#define		sm44			s4c_addr.bit.b4		/* CLK polarity select bit */
#define		sm45			s4c_addr.bit.b5		/* Transfer direction select bit */
#define		sm46			s4c_addr.bit.b6		/* Synchronous clock select bit */
#define		sm47			s4c_addr.bit.b7		/* Sout4 initial value set bit */

/*------------------------------------------------------
	SI/O4 bit rate generator ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
union byte_def s4brg_addr;
#define		s4brg			s4brg_addr.byte

/*------------------------------------------------------
	UART0 special mode register 4
------------------------------------------------------*/
union byte_def u0smr4_addr;
#define		u0smr4			u0smr4_addr.byte

#define		stareq_u0smr4	u0smr4_addr.bit.b0	/* Start condition generate bit */
#define		rstareq_u0smr4	u0smr4_addr.bit.b1	/* Restart condition generate bit */
#define		stpreq_u0smr4	u0smr4_addr.bit.b2	/* Stop condition generate bit */
#define		stspsel_u0smr4	u0smr4_addr.bit.b3	/* SCL,SDA output select bit */
#define		ackd_u0smr4		u0smr4_addr.bit.b4	/* ACK data bit */
#define		ackc_u0smr4		u0smr4_addr.bit.b5	/* ACK data output enable bit */
#define		sclhi_u0smr4	u0smr4_addr.bit.b6	/* SCL output stop enable bit */
#define		swc9_u0smr4		u0smr4_addr.bit.b7	/* Final bit L hold enable bit */

/*------------------------------------------------------
	UART0 special mode register 3
------------------------------------------------------*/
union byte_def u0smr3_addr;
#define		u0smr3			u0smr3_addr.byte

#define		ckph_u0smr3		u0smr3_addr.bit.b1	/* Clock phase set bit */
#define		nodc_u0smr3		u0smr3_addr.bit.b3	/* Clock output set bit */
#define		dl0_u0smr3		u0smr3_addr.bit.b5	/* SDA0(TxD0) digital delay setup bit */
#define		dl1_u0smr3		u0smr3_addr.bit.b6	/* SDA0(TxD0) digital delay setup bit */
#define		dl2_u0smr3		u0smr3_addr.bit.b7	/* SDA0(TxD0) digital delay setup bit */

/*------------------------------------------------------
	UART0 special mode register 2
------------------------------------------------------*/
union byte_def u0smr2_addr;
#define		u0smr2			u0smr2_addr.byte

#define		iicm2_u0smr2	u0smr2_addr.bit.b0	/* IIC mode selection bit 2 */
#define		csc_u0smr2		u0smr2_addr.bit.b1	/* Clock-synchronous bit */
#define		swc_u0smr2		u0smr2_addr.bit.b2	/* SCL wait output bit */
#define		als_u0smr2		u0smr2_addr.bit.b3	/* SDA output stop bit */
#define		stac_u0smr2		u0smr2_addr.bit.b4	/* UART0 initialization bit */
#define		swc2_u0smr2		u0smr2_addr.bit.b5	/* SCL wait output bit 2 */
#define		sdhi_u0smr2		u0smr2_addr.bit.b6	/* SDA output disable bit */

/*------------------------------------------------------
	UART0 special mode register
------------------------------------------------------*/
union byte_def u0smr_addr;
#define		u0smr			u0smr_addr.byte

#define		iicm_u0smr		u0smr_addr.bit.b0	/* IIC mode selection bit */
#define		abc_u0smr		u0smr_addr.bit.b1	/* Arbitration lost detecting flag control bit */
#define		bbs_u0smr		u0smr_addr.bit.b2	/* Bus busy flag */
#define		lsyn_u0smr		u0smr_addr.bit.b3	/* SCLL sync output enable bit */
#define		abscs_u0smr		u0smr_addr.bit.b4	/* Bus collision detect sampling clock select bit */
#define		acse_u0smr		u0smr_addr.bit.b5	/* Auto clear function select bit of transmit enable bit */
#define		sss_u0smr		u0smr_addr.bit.b6	/* Transmit start condition select bit */

/*------------------------------------------------------
	UART1 special mode register 4
------------------------------------------------------*/
union byte_def u1smr4_addr;
#define		u1smr4			u1smr4_addr.byte

#define		stareq_u1smr4	u1smr4_addr.bit.b0	/* Start condition generate bit */
#define		rstareq_u1smr4	u1smr4_addr.bit.b1	/* Restart condition generate bit */
#define		stpreq_u1smr4	u1smr4_addr.bit.b2	/* Stop condition generate bit */
#define		stspsel_u1smr4	u1smr4_addr.bit.b3	/* SCL,SDA output select bit */
#define		ackd_u1smr4		u1smr4_addr.bit.b4	/* ACK data bit */
#define		ackc_u1smr4		u1smr4_addr.bit.b5	/* ACK data output enable bit */
#define		sclhi_u1smr4	u1smr4_addr.bit.b6	/* SCL output stop enable bit */
#define		swc9_u1smr4		u1smr4_addr.bit.b7	/* Final bit L hold enable bit */

/*------------------------------------------------------
	UART1 special mode register 3
------------------------------------------------------*/
union byte_def u1smr3_addr;
#define		u1smr3			u1smr3_addr.byte

#define		ckph_u1smr3		u1smr3_addr.bit.b1	/* Clock phase set bit */
#define		nodc_u1smr3		u1smr3_addr.bit.b3	/* Clock output set bit */
#define		dl0_u1smr3		u1smr3_addr.bit.b5	/* SDA1(TxD1) digital delay setup bit */
#define		dl1_u1smr3		u1smr3_addr.bit.b6	/* SDA1(TxD1) digital delay setup bit */
#define		dl2_u1smr3		u1smr3_addr.bit.b7	/* SDA1(TxD1) digital delay setup bit */

/*------------------------------------------------------
	UART1 special mode register 2
------------------------------------------------------*/
union byte_def u1smr2_addr;
#define		u1smr2			u1smr2_addr.byte

#define		iicm2_u1smr2	u1smr2_addr.bit.b0	/* IIC mode selection bit 2 */
#define		csc_u1smr2		u1smr2_addr.bit.b1	/* Clock-synchronous bit */
#define		swc_u1smr2		u1smr2_addr.bit.b2	/* SCL wait output bit */
#define		als_u1smr2		u1smr2_addr.bit.b3	/* SDA output stop bit */
#define		stac_u1smr2		u1smr2_addr.bit.b4	/* UART0 initialization bit */
#define		swc2_u1smr2		u1smr2_addr.bit.b5	/* SCL wait output bit 2 */
#define		sdhi_u1smr2		u1smr2_addr.bit.b6	/* SDA output disable bit */

/*------------------------------------------------------
	UART1 special mode register
------------------------------------------------------*/
union byte_def u1smr_addr;
#define		u1smr			u1smr_addr.byte

#define		iicm_u1smr		u1smr_addr.bit.b0	/* IIC mode selection bit */
#define		abc_u1smr		u1smr_addr.bit.b1	/* Arbitration lost detecting flag control bit */
#define		bbs_u1smr		u1smr_addr.bit.b2	/* Bus busy flag */
#define		lsyn_u1smr		u1smr_addr.bit.b3	/* SCLL sync output enable bit */
#define		abscs_u1smr		u1smr_addr.bit.b4	/* Bus collision detect sampling clock select bit */
#define		acse_u1smr		u1smr_addr.bit.b5	/* Auto clear function select bit of transmit enable bit */
#define		sss_u1smr		u1smr_addr.bit.b6	/* Transmit start condition select bit */

/*------------------------------------------------------
	UART2 special mode register 4
------------------------------------------------------*/
union byte_def u2smr4_addr;
#define		u2smr4			u2smr4_addr.byte

#define		stareq_u2smr4	u2smr4_addr.bit.b0	/* Start condition generate bit */
#define		rstareq_u2smr4	u2smr4_addr.bit.b1	/* Restart condition generate bit */
#define		stpreq_u2smr4	u2smr4_addr.bit.b2	/* Stop condition generate bit */
#define		stspsel_u2smr4	u2smr4_addr.bit.b3	/* SCL,SDA output select bit */
#define		ackd_u2smr4		u2smr4_addr.bit.b4	/* ACK data bit */
#define		ackc_u2smr4		u2smr4_addr.bit.b5	/* ACK data output enable bit */
#define		sclhi_u2smr4	u2smr4_addr.bit.b6	/* SCL output stop enable bit */
#define		swc9_u2smr4		u2smr4_addr.bit.b7	/* Final bit L hold enable bit */

/*------------------------------------------------------
	UART2 special mode register 3
------------------------------------------------------*/
union byte_def u2smr3_addr;
#define		u2smr3			u2smr3_addr.byte

#define		ckph_u2smr3		u2smr3_addr.bit.b1	/* Clock phase set bit */
#define		nodc_u2smr3		u2smr3_addr.bit.b3	/* Clock output set bit */
#define		dl0_u2smr3		u2smr3_addr.bit.b5	/* SDA2(TxD2) digital delay setup bit */
#define		dl1_u2smr3		u2smr3_addr.bit.b6	/* SDA2(TxD2) digital delay setup bit */
#define		dl2_u2smr3		u2smr3_addr.bit.b7	/* SDA2(TxD2) digital delay setup bit */

/*------------------------------------------------------
	UART2 special mode register 2
------------------------------------------------------*/
union byte_def u2smr2_addr;
#define		u2smr2			u2smr2_addr.byte

#define		iicm2_u2smr2	u2smr2_addr.bit.b0	/* IIC mode selection bit 2 */
#define		csc_u2smr2		u2smr2_addr.bit.b1	/* Clock-synchronous bit */
#define		swc_u2smr2		u2smr2_addr.bit.b2	/* SCL wait output bit */
#define		als_u2smr2		u2smr2_addr.bit.b3	/* SDA output stop bit */
#define		stac_u2smr2		u2smr2_addr.bit.b4	/* UART0 initialization bit */
#define		swc2_u2smr2		u2smr2_addr.bit.b5	/* SCL wait output bit 2 */
#define		sdhi_u2smr2		u2smr2_addr.bit.b6	/* SDA output disable bit */

/*------------------------------------------------------
	UART2 special mode register
------------------------------------------------------*/
union byte_def u2smr_addr;
#define		u2smr			u2smr_addr.byte

#define		iicm_u2smr		u2smr_addr.bit.b0	/* IIC mode selection bit */
#define		abc_u2smr		u2smr_addr.bit.b1	/* Arbitration lost detecting flag control bit */
#define		bbs_u2smr		u2smr_addr.bit.b2	/* Bus busy flag */
#define		lsyn_u2smr		u2smr_addr.bit.b3	/* SCLL sync output enable bit */
#define		abscs_u2smr		u2smr_addr.bit.b4	/* Bus collision detect sampling clock select bit */
#define		acse_u2smr		u2smr_addr.bit.b5	/* Auto clear function select bit of transmit enable bit */
#define		sss_u2smr		u2smr_addr.bit.b6	/* Transmit start condition select bit */

/*------------------------------------------------------
	UART2 transmit/receive mode register
------------------------------------------------------*/
union byte_def u2mr_addr;
#define		u2mr			u2mr_addr.byte

#define		smd0_u2mr		u2mr_addr.bit.b0	/* Serial I/O mode select bit */
#define		smd1_u2mr		u2mr_addr.bit.b1	/* Serial I/O mode select bit */
#define		smd2_u2mr		u2mr_addr.bit.b2	/* Serial I/O mode select bit */
#define		ckdir_u2mr		u2mr_addr.bit.b3	/* Internal/external clock select bit */
#define		stps_u2mr		u2mr_addr.bit.b4	/* Stop bit length select bit */
#define		pry_u2mr		u2mr_addr.bit.b5	/* Odd/even parity select bit */
#define		prye_u2mr		u2mr_addr.bit.b6	/* Parity enable bit */
#define		iopol_u2mr		u2mr_addr.bit.b7	/* TxD RxD I/O polarity reverse bit */

/*------------------------------------------------------
	UART2 bit rate generator ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
union byte_def u2brg_addr;
#define		u2brg			u2brg_addr.byte

/*------------------------------------------------------
	UART2 transmit/receive control register 0
------------------------------------------------------*/
union byte_def u2c0_addr;
#define		u2c0			u2c0_addr.byte

#define		clk0_u2c0		u2c0_addr.bit.b0	/* BRG count source select bit */
#define		clk1_u2c0		u2c0_addr.bit.b1	/* BRG count source select bit */
#define		crs_u2c0		u2c0_addr.bit.b2	/* CTS~/RTS~ function select bit */
#define		txept_u2c0		u2c0_addr.bit.b3	/* Transmit register empty flag */
#define		crd_u2c0		u2c0_addr.bit.b4	/* CTS~/RTS~ disable bit */
#define		nch_u2c0		u2c0_addr.bit.b5	/* Data output select bit */
#define		ckpol_u2c0		u2c0_addr.bit.b6	/* CLK polarity select bit */
#define		uform_u2c0		u2c0_addr.bit.b7	/* Transfer format select bit */

/*------------------------------------------------------
	UART2 transmit/receive control register 1			
------------------------------------------------------*/
union byte_def u2c1_addr;
#define		u2c1			u2c1_addr.byte

#define		te_u2c1			u2c1_addr.bit.b0	/* Transmit enable bit */
#define		ti_u2c1			u2c1_addr.bit.b1	/* Transmit buffer empty flag */
#define		re_u2c1			u2c1_addr.bit.b2	/* Receive enable bit */
#define		ri_u2c1			u2c1_addr.bit.b3	/* Receive complete flag */
#define		u2irs			u2c1_addr.bit.b4	/* UART2 transmit interrupt cause select bit */
#define		u2rrm			u2c1_addr.bit.b5	/* UART2 continuous receive mode enable bit */
#define		u2lch			u2c1_addr.bit.b6	/* Data logic select bit */
#define		u2ere			u2c1_addr.bit.b7	/* Error signal output enable bit */

/*------------------------------------------------------
	Count start flag
------------------------------------------------------*/
union byte_def tabsr_addr;
#define		tabsr			tabsr_addr.byte

#define		ta0s			tabsr_addr.bit.b0	/* Timer A0 count start flag */
#define		ta1s			tabsr_addr.bit.b1	/* Timer A1 count start flag */
#define		ta2s			tabsr_addr.bit.b2	/* Timer A2 count start flag */
#define		ta3s			tabsr_addr.bit.b3	/* Timer A3 count start flag */
#define		ta4s			tabsr_addr.bit.b4	/* Timer A4 count start flag */
#define		tb0s			tabsr_addr.bit.b5	/* Timer B0 count start flag */
#define		tb1s			tabsr_addr.bit.b6	/* Timer B1 count start flag */
#define		tb2s			tabsr_addr.bit.b7	/* Timer B2 count start flag */

/*------------------------------------------------------
	Clock prescaler reset flag
------------------------------------------------------*/
union byte_def cpsrf_addr;
#define		cpsrf			cpsrf_addr.byte

#define		cpsr			cpsrf_addr.bit.b7	/* Clock prescaler reset flag */

/*------------------------------------------------------
	One-shot start flag
------------------------------------------------------*/
union byte_def onsf_addr;
#define		onsf			onsf_addr.byte

#define		ta0os			onsf_addr.bit.b0	/* Timer A0 one-shot start flag */
#define		ta1os			onsf_addr.bit.b1	/* Timer A1 one-shot start flag */
#define		ta2os			onsf_addr.bit.b2	/* Timer A2 one-shot start flag */
#define		ta3os			onsf_addr.bit.b3	/* Timer A3 one-shot start flag */
#define		ta4os			onsf_addr.bit.b4	/* Timer A4 one-shot start flag */
#define		tazie			onsf_addr.bit.b5	/* Z phase input enable bit */
#define		ta0tgl			onsf_addr.bit.b6	/* Timer A0 event/trigger select bit */
#define		ta0tgh			onsf_addr.bit.b7	/* Timer A0 event/trigger select bit */

/*------------------------------------------------------
	Trigger select register
------------------------------------------------------*/
union byte_def trgsr_addr;
#define		trgsr			trgsr_addr.byte

#define		ta1tgl			trgsr_addr.bit.b0	/* Timer A1 event/trigger select bit */
#define		ta1tgh			trgsr_addr.bit.b1	/* Timer A1 event/trigger select bit */
#define		ta2tgl			trgsr_addr.bit.b2	/* Timer A2 event/trigger select bit */
#define		ta2tgh			trgsr_addr.bit.b3	/* Timer A2 event/trigger select bit */
#define		ta3tgl			trgsr_addr.bit.b4	/* Timer A3 event/trigger select bit */
#define		ta3tgh			trgsr_addr.bit.b5	/* Timer A3 event/trigger select bit */
#define		ta4tgl			trgsr_addr.bit.b6	/* Timer A4 event/trigger select bit */
#define		ta4tgh			trgsr_addr.bit.b7	/* Timer A4 event/trigger select bit */

/*------------------------------------------------------
	 Timer A0 mode register
------------------------------------------------------*/
union byte_def ta0mr_addr;
#define		ta0mr			ta0mr_addr.byte

#define		tmod0_ta0mr		ta0mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_ta0mr		ta0mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_ta0mr		ta0mr_addr.bit.b2
#define		mr1_ta0mr		ta0mr_addr.bit.b3
#define		mr2_ta0mr		ta0mr_addr.bit.b4
#define		mr3_ta0mr		ta0mr_addr.bit.b5
#define		tck0_ta0mr		ta0mr_addr.bit.b6	/* Count source select bit */
#define		tck1_ta0mr		ta0mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer A1 mode register
------------------------------------------------------*/
union byte_def ta1mr_addr;
#define		ta1mr			ta1mr_addr.byte

#define		tmod0_ta1mr		ta1mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_ta1mr		ta1mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_ta1mr		ta1mr_addr.bit.b2
#define		mr1_ta1mr		ta1mr_addr.bit.b3
#define		mr2_ta1mr		ta1mr_addr.bit.b4
#define		mr3_ta1mr		ta1mr_addr.bit.b5
#define		tck0_ta1mr		ta1mr_addr.bit.b6	/* Count source select bit */
#define		tck1_ta1mr		ta1mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer A2 mode register
------------------------------------------------------*/
union byte_def ta2mr_addr;
#define		ta2mr			ta2mr_addr.byte

#define		tmod0_ta2mr		ta2mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_ta2mr		ta2mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_ta2mr		ta2mr_addr.bit.b2
#define		mr1_ta2mr		ta2mr_addr.bit.b3
#define		mr2_ta2mr		ta2mr_addr.bit.b4
#define		mr3_ta2mr		ta2mr_addr.bit.b5
#define		tck0_ta2mr		ta2mr_addr.bit.b6	/* Count source select bit */
#define		tck1_ta2mr		ta2mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer A3 mode register
------------------------------------------------------*/
union byte_def ta3mr_addr;
#define		ta3mr			ta3mr_addr.byte

#define		tmod0_ta3mr		ta3mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_ta3mr		ta3mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_ta3mr		ta3mr_addr.bit.b2
#define		mr1_ta3mr		ta3mr_addr.bit.b3
#define		mr2_ta3mr		ta3mr_addr.bit.b4
#define		mr3_ta3mr		ta3mr_addr.bit.b5
#define		tck0_ta3mr		ta3mr_addr.bit.b6	/* Count source select bit */
#define		tck1_ta3mr		ta3mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer A4 mode register
------------------------------------------------------*/
union byte_def ta4mr_addr;
#define		ta4mr			ta4mr_addr.byte

#define		tmod0_ta4mr		ta4mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_ta4mr		ta4mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_ta4mr		ta4mr_addr.bit.b2
#define		mr1_ta4mr		ta4mr_addr.bit.b3
#define		mr2_ta4mr		ta4mr_addr.bit.b4
#define		mr3_ta4mr		ta4mr_addr.bit.b5
#define		tck0_ta4mr		ta4mr_addr.bit.b6	/* Count source select bit */
#define		tck1_ta4mr		ta4mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer B0 mode register
------------------------------------------------------*/
union byte_def tb0mr_addr;
#define		tb0mr			tb0mr_addr.byte

#define		tmod0_tb0mr		tb0mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_tb0mr		tb0mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_tb0mr		tb0mr_addr.bit.b2
#define		mr1_tb0mr		tb0mr_addr.bit.b3
#define		mr2_tb0mr		tb0mr_addr.bit.b4
#define		mr3_tb0mr		tb0mr_addr.bit.b5
#define		tck0_tb0mr		tb0mr_addr.bit.b6	/* Count source select bit */
#define		tck1_tb0mr		tb0mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer B1 mode register
------------------------------------------------------*/
union byte_def tb1mr_addr;
#define		tb1mr			tb1mr_addr.byte

#define		tmod0_tb1mr		tb1mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_tb1mr		tb1mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_tb1mr		tb1mr_addr.bit.b2
#define		mr1_tb1mr		tb1mr_addr.bit.b3
#define		mr3_tb1mr		tb1mr_addr.bit.b5
#define		tck0_tb1mr		tb1mr_addr.bit.b6	/* Count source select bit */
#define		tck1_tb1mr		tb1mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	 Timer B2 mode register
------------------------------------------------------*/
union byte_def tb2mr_addr;
#define		tb2mr			tb2mr_addr.byte

#define		tmod0_tb2mr		tb2mr_addr.bit.b0	/* Operation mode select bit */
#define		tmod1_tb2mr		tb2mr_addr.bit.b1	/* Operation mode select bit */
#define		mr0_tb2mr		tb2mr_addr.bit.b2
#define		mr1_tb2mr		tb2mr_addr.bit.b3
#define		mr3_tb2mr		tb2mr_addr.bit.b5
#define		tck0_tb2mr		tb2mr_addr.bit.b6	/* Count source select bit */
#define		tck1_tb2mr		tb2mr_addr.bit.b7	/* Count source select bit */

/*------------------------------------------------------
	Timer B2 special mode register
------------------------------------------------------*/
union byte_def tb2sc_addr;
#define		tb2sc			tb2sc_addr.byte

#define		pwcon			tb2sc_addr.bit.b0	/* Timer B2 reload timing switching bit */
#define		ivpcr1			tb2sc_addr.bit.b1	/* Three phase output port NMI control bit 1 */

/*------------------------------------------------------
	UART0 transmit/receive mode register
------------------------------------------------------*/
union byte_def u0mr_addr;
#define		u0mr			u0mr_addr.byte

#define		smd0_u0mr		u0mr_addr.bit.b0	/* Serial I/O mode select bit */
#define		smd1_u0mr		u0mr_addr.bit.b1	/* Serial I/O mode select bit */
#define		smd2_u0mr		u0mr_addr.bit.b2	/* Serial I/O mode select bit */
#define		ckdir_u0mr		u0mr_addr.bit.b3	/* Internal/external clock select bit */
#define		stps_u0mr		u0mr_addr.bit.b4	/* Stop bit length select bit */
#define		pry_u0mr		u0mr_addr.bit.b5	/* Odd/even parity select bit */
#define		prye_u0mr		u0mr_addr.bit.b6	/* Parity enable bit */
#define		iopol_u0mr		u0mr_addr.bit.b7	/* TxD,RxD I/O polarity reverse bit */

/*------------------------------------------------------
	UART0 bit rate generator ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
union byte_def u0brg_addr;
#define		u0brg			u0brg_addr.byte

/*------------------------------------------------------
	UART0 transmit/receive control register 0
------------------------------------------------------*/
union byte_def u0c0_addr;
#define		u0c0			u0c0_addr.byte

#define		clk0_u0c0		u0c0_addr.bit.b0	/* BRG count source select bit */
#define		clk1_u0c0		u0c0_addr.bit.b1	/* BRG count source select bit */
#define		crs_u0c0		u0c0_addr.bit.b2	/* CTS~/RTS~ function select bit */
#define		txept_u0c0		u0c0_addr.bit.b3	/* Transmit register empty flag */
#define		crd_u0c0		u0c0_addr.bit.b4	/* CTS~/RTS~ disable bit */
#define		nch_u0c0		u0c0_addr.bit.b5	/* Data output select bit */
#define		ckpol_u0c0		u0c0_addr.bit.b6	/* CLK polarity select bit */
#define		uform_u0c0		u0c0_addr.bit.b7	/* Transfer format select bit */

/*------------------------------------------------------
	UART0 transmit/receive control register 1
------------------------------------------------------*/
union byte_def u0c1_addr;
#define		u0c1			u0c1_addr.byte

#define		te_u0c1			u0c1_addr.bit.b0	/* Transmit enable bit */
#define		ti_u0c1			u0c1_addr.bit.b1	/* Transmit buffer empty flag */
#define		re_u0c1			u0c1_addr.bit.b2	/* Receive enable bit */
#define		ri_u0c1			u0c1_addr.bit.b3	/* Receive complete flag */
#define		u0lch			u0c1_addr.bit.b6	/* Data logic select bit */
#define		u0ere			u0c1_addr.bit.b7	/* Error signal output enable bit */

/*------------------------------------------------------
	UART0 transmit/receive mode register
------------------------------------------------------*/
union byte_def u1mr_addr;
#define		u1mr			u1mr_addr.byte

#define		smd0_u1mr		u1mr_addr.bit.b0	/* Serial I/O mode select bit */
#define		smd1_u1mr		u1mr_addr.bit.b1	/* Serial I/O mode select bit */
#define		smd2_u1mr		u1mr_addr.bit.b2	/* Serial I/O mode select bit */
#define		ckdir_u1mr		u1mr_addr.bit.b3	/* Internal/external clock select bit */
#define		stps_u1mr		u1mr_addr.bit.b4	/* Stop bit length select bit */
#define		pry_u1mr		u1mr_addr.bit.b5	/* Odd/even parity select bit */
#define		prye_u1mr		u1mr_addr.bit.b6	/* Parity enable bit */
#define		iopol_u1mr		u1mr_addr.bit.b7	/* TxD,RxD I/O polarity reverse bit */

/*------------------------------------------------------
	UART1 bit rate generator ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
union byte_def u1brg_addr;
#define		u1brg			u1brg_addr.byte

/*------------------------------------------------------
	UART1 transmit/receive control register 0
------------------------------------------------------*/
union byte_def u1c0_addr;
#define		u1c0			u1c0_addr.byte

#define		clk0_u1c0		u1c0_addr.bit.b0	/* BRG count source select bit */
#define		clk1_u1c0		u1c0_addr.bit.b1	/* BRG count source select bit */
#define		crs_u1c0		u1c0_addr.bit.b2	/* CTS~/RTS~ function select bit */
#define		txept_u1c0		u1c0_addr.bit.b3	/* Transmit register empty flag */
#define		crd_u1c0		u1c0_addr.bit.b4	/* CTS~/RTS~ disable bit */
#define		nch_u1c0		u1c0_addr.bit.b5	/* Data output select bit */
#define		ckpol_u1c0		u1c0_addr.bit.b6	/* CLK polarity select bit */
#define		uform_u1c0		u1c0_addr.bit.b7	/* Transfer format select bit */

/*------------------------------------------------------
	UART1 transmit/receive control register 1
------------------------------------------------------*/
union byte_def u1c1_addr;
#define		u1c1			u1c1_addr.byte

#define		te_u1c1			u1c1_addr.bit.b0	/* Transmit enable bit */
#define		ti_u1c1			u1c1_addr.bit.b1	/* Transmit buffer empty flag */
#define		re_u1c1			u1c1_addr.bit.b2	/* Receive enable bit */
#define		ri_u1c1			u1c1_addr.bit.b3	/* Receive complete flag */
#define		u1lch			u1c1_addr.bit.b6	/* Data logic select bit */
#define		u1ere			u1c1_addr.bit.b7	/* Error signal output enable bit */

/*------------------------------------------------------
	UART transmit/receive control register 2
------------------------------------------------------*/
union byte_def ucon_addr;
#define		ucon			ucon_addr.byte

#define		u0irs			ucon_addr.bit.b0	/* UART0 transmit interrupt cause select bit */
#define		u1irs			ucon_addr.bit.b1	/* UART1 transmit interrupt cause select bit */
#define		u0rrm			ucon_addr.bit.b2	/* UART0 continuous receive mode enable bit */
#define		u1rrm			ucon_addr.bit.b3	/* UART1 continuous receive mode enable bit */
#define		clkmd0			ucon_addr.bit.b4	/* CLK/CLKS select bit 0 */
#define		clkmd1			ucon_addr.bit.b5	/* CLK/CLKS select bit 1 */
#define		rcsp			ucon_addr.bit.b6	/* Separate CTS~/RTS~ bit */

/*------------------------------------------------------
	Flash identification register
------------------------------------------------------*/
union byte_def fidr_addr;
#define		fidr			fidr_addr.byte

#define		fidr0			fidr_addr.bit.b0	/* Flash identification value */
#define		fidr1			fidr_addr.bit.b1	/* Flash identification value */

/*------------------------------------------------------
	DMA0 request cause select register
------------------------------------------------------*/
union byte_def dm0sl_addr;
#define		dm0sl			dm0sl_addr.byte

#define		dsel0_dm0sl		dm0sl_addr.bit.b0	/* DMA request cause select bit */
#define		dsel1_dm0sl		dm0sl_addr.bit.b1	/* DMA request cause select bit */
#define		dsel2_dm0sl		dm0sl_addr.bit.b2	/* DMA request cause select bit */
#define		dsel3_dm0sl		dm0sl_addr.bit.b3	/* DMA request cause select bit */
#define		dms_dm0sl		dm0sl_addr.bit.b6	/* DMA request cause expansion select bit */
#define		dsr_dm0sl		dm0sl_addr.bit.b7	/* Software DMA request bit */

/*------------------------------------------------------
	DMA1 request cause select register
------------------------------------------------------*/
union byte_def dm1sl_addr;
#define		dm1sl			dm1sl_addr.byte

#define		dsel0_dm1sl		dm1sl_addr.bit.b0	/* DMA request cause select bit */
#define		dsel1_dm1sl		dm1sl_addr.bit.b1	/* DMA request cause select bit */
#define		dsel2_dm1sl 	dm1sl_addr.bit.b2	/* DMA request cause select bit */
#define		dsel3_dm1sl 	dm1sl_addr.bit.b3	/* DMA request cause select bit */
#define		dms_dm1sl		dm1sl_addr.bit.b6	/* DMA request cause expansion select bit */
#define		dsr_dm1sl		dm1sl_addr.bit.b7	/* Software DMA request bit */

/*------------------------------------------------------
	CRC input register
------------------------------------------------------*/
union byte_def crcin_addr;
#define		crcin			crcin_addr.byte

/*------------------------------------------------------
	A-D control register 2
------------------------------------------------------*/
union byte_def adcon2_addr;
#define		adcon2			adcon2_addr.byte

#define		smp				adcon2_addr.bit.b0	/* A-D conversion method select bit */
#define		adgsel0			adcon2_addr.bit.b1	/* A-D input group select bit */
#define		adgsel1			adcon2_addr.bit.b2	/* A-D input group select bit */
#define		cks2			adcon2_addr.bit.b4	/* Frequency select bit 2 */

/*------------------------------------------------------
	A-D control register 0
------------------------------------------------------*/
union byte_def adcon0_addr;
#define		adcon0			adcon0_addr.byte

#define		ch0				adcon0_addr.bit.b0	/* Analog input pin select bit */
#define		ch1				adcon0_addr.bit.b1	/* Analog input pin select bit */
#define		ch2				adcon0_addr.bit.b2	/* Analog input pin select bit */
#define		md0				adcon0_addr.bit.b3	/* A-D operation mode select bit 0 */
#define		md1				adcon0_addr.bit.b4	/* A-D operation mode select bit 0 */
#define		trg				adcon0_addr.bit.b5	/* Trigger select bit */
#define		adst			adcon0_addr.bit.b6	/* A-D conversion start flag */
#define		cks0			adcon0_addr.bit.b7	/* Frequency select bit 0 */

/*------------------------------------------------------
	A-D control register 1
------------------------------------------------------*/
union byte_def adcon1_addr;
#define		adcon1			adcon1_addr.byte

#define		scan0			adcon1_addr.bit.b0	/* A-D sweep pin select bit */
#define		scan1			adcon1_addr.bit.b1	/* A-D sweep pin select bit */
#define		md2				adcon1_addr.bit.b2	/* A-D operation mode select bit 1 */
#define		bits			adcon1_addr.bit.b3	/* 8/10-bit mode select bit */
#define		cks1			adcon1_addr.bit.b4	/* Frequency select bit 1 */
#define		vcut			adcon1_addr.bit.b5	/* Vref connect bit */
#define		opa0			adcon1_addr.bit.b6	/* External op-amp connection mode bit */
#define		opa1			adcon1_addr.bit.b7	/* External op-amp connection mode bit */

/*------------------------------------------------------
	D-A control register
------------------------------------------------------*/
union byte_def dacon_addr;
#define		dacon			dacon_addr.byte

#define		da0e			dacon_addr.bit.b0	/* D-A0 output enable bit */
#define		da1e			dacon_addr.bit.b1	/* D-A1 output enable bit */

/*------------------------------------------------------
	Port P14 control register (128-pin version)
------------------------------------------------------*/
union byte_def pc14_addr;
#define		pc14			pc14_addr.byte

#define		p140			pc14_addr.bit.b0	/* Port P14_0 register */
#define		p141			pc14_addr.bit.b1	/* Port P14_1 register */
#define		pd140			pc14_addr.bit.b4	/* Port P14_0 direction register */
#define		pd141			pc14_addr.bit.b5	/* Port P14_1 direction register */

/*------------------------------------------------------
	Pull-up control register 3 (128-pin version)
------------------------------------------------------*/
union byte_def pur3_addr;
#define		pur3			pur3_addr.byte

#define		pu30			pur3_addr.bit.b0	/* P11_0 to P11_3 pull-up */
#define		pu31			pur3_addr.bit.b1	/* P11_4 to P11_7 pull-up */
#define		pu32			pur3_addr.bit.b2	/* P12_0 to P12_3 pull-up */
#define		pu33			pur3_addr.bit.b3	/* P12_4 to P12_7 pull-up */
#define		pu34			pur3_addr.bit.b4	/* P13_0 to P13_3 pull-up */
#define		pu35			pur3_addr.bit.b5	/* P13_4 to P13_7 pull-up */
#define		pu36			pur3_addr.bit.b6	/* P14_0,P14_1 pull-up */
#define		pu37			pur3_addr.bit.b7	/* P11 to P14 effective bit */

/*------------------------------------------------------
	Port P0 register
------------------------------------------------------*/
union byte_def p0_addr;
#define		p0				p0_addr.byte

#define		p0_0			p0_addr.bit.b0		/* Port P0_0 register */
#define		p0_1			p0_addr.bit.b1		/* Port P0_1 register */
#define		p0_2			p0_addr.bit.b2		/* Port P0_2 register */
#define		p0_3			p0_addr.bit.b3		/* Port P0_3 register */
#define		p0_4			p0_addr.bit.b4		/* Port P0_4 register */
#define		p0_5			p0_addr.bit.b5		/* Port P0_5 register */
#define		p0_6			p0_addr.bit.b6		/* Port P0_6 register */
#define		p0_7			p0_addr.bit.b7		/* Port P0_7 register */

/*------------------------------------------------------
	Port P1 register
------------------------------------------------------*/
union byte_def p1_addr;
#define		p1				p1_addr.byte

#define		p1_0			p1_addr.bit.b0		/* Port P1_0 register */
#define		p1_1			p1_addr.bit.b1		/* Port P1_1 register */
#define		p1_2			p1_addr.bit.b2		/* Port P1_2 register */
#define		p1_3			p1_addr.bit.b3		/* Port P1_3 register */
#define		p1_4			p1_addr.bit.b4		/* Port P1_4 register */
#define		p1_5			p1_addr.bit.b5		/* Port P1_5 register */
#define		p1_6			p1_addr.bit.b6		/* Port P1_6 register */
#define		p1_7			p1_addr.bit.b7		/* Port P1_7 register */

/*------------------------------------------------------
	Port P0 direction register
------------------------------------------------------*/
union byte_def pd0_addr;
#define		pd0				pd0_addr.byte

#define		pd0_0			pd0_addr.bit.b0		/* Port P0_0 direction register */
#define		pd0_1			pd0_addr.bit.b1		/* Port P0_1 direction register */
#define		pd0_2			pd0_addr.bit.b2		/* Port P0_2 direction register */
#define		pd0_3			pd0_addr.bit.b3		/* Port P0_3 direction register */
#define		pd0_4			pd0_addr.bit.b4		/* Port P0_4 direction register */
#define		pd0_5			pd0_addr.bit.b5		/* Port P0_5 direction register */
#define		pd0_6			pd0_addr.bit.b6		/* Port P0_6 direction register */
#define		pd0_7			pd0_addr.bit.b7		/* Port P0_7 direction register */

/*------------------------------------------------------
	Port P1 direction register
------------------------------------------------------*/
union byte_def pd1_addr;
#define		pd1				pd1_addr.byte

#define		pd1_0			pd1_addr.bit.b0		/* Port P1_0 direction register */
#define		pd1_1			pd1_addr.bit.b1		/* Port P1_1 direction register */
#define		pd1_2			pd1_addr.bit.b2		/* Port P1_2 direction register */
#define		pd1_3			pd1_addr.bit.b3		/* Port P1_3 direction register */
#define		pd1_4			pd1_addr.bit.b4		/* Port P1_4 direction register */
#define		pd1_5			pd1_addr.bit.b5		/* Port P1_5 direction register */
#define		pd1_6			pd1_addr.bit.b6		/* Port P1_6 direction register */
#define		pd1_7			pd1_addr.bit.b7		/* Port P1_7 direction register */

/*------------------------------------------------------
	Port P2 register
------------------------------------------------------*/
union byte_def p2_addr;
#define		p2				p2_addr.byte

#define		p2_0			p2_addr.bit.b0		/* Port P2_0 register */
#define		p2_1			p2_addr.bit.b1		/* Port P2_1 register */
#define		p2_2			p2_addr.bit.b2		/* Port P2_2 register */
#define		p2_3			p2_addr.bit.b3		/* Port P2_3 register */
#define		p2_4			p2_addr.bit.b4		/* Port P2_4 register */
#define		p2_5			p2_addr.bit.b5		/* Port P2_5 register */
#define		p2_6			p2_addr.bit.b6		/* Port P2_6 register */
#define		p2_7			p2_addr.bit.b7		/* Port P2_7 register */

/*------------------------------------------------------
	Port P3 register
------------------------------------------------------*/
union byte_def p3_addr;
#define		p3				p3_addr.byte

#define		p3_0			p3_addr.bit.b0		/* Port P3_0 register */
#define		p3_1			p3_addr.bit.b1		/* Port P3_1 register */
#define		p3_2			p3_addr.bit.b2		/* Port P3_2 register */
#define		p3_3			p3_addr.bit.b3		/* Port P3_3 register */
#define		p3_4			p3_addr.bit.b4		/* Port P3_4 register */
#define		p3_5			p3_addr.bit.b5		/* Port P3_5 register */
#define		p3_6			p3_addr.bit.b6		/* Port P3_6 register */
#define		p3_7			p3_addr.bit.b7		/* Port P3_7 register */

/*------------------------------------------------------
	Port P2 direction register
------------------------------------------------------*/
union byte_def pd2_addr;
#define		pd2				pd2_addr.byte

#define		pd2_0			pd2_addr.bit.b0		/* Port P2_0 direction register */
#define		pd2_1			pd2_addr.bit.b1		/* Port P2_1 direction register */
#define		pd2_2			pd2_addr.bit.b2		/* Port P2_2 direction register */
#define		pd2_3			pd2_addr.bit.b3		/* Port P2_3 direction register */
#define		pd2_4			pd2_addr.bit.b4		/* Port P2_4 direction register */
#define		pd2_5			pd2_addr.bit.b5		/* Port P2_5 direction register */
#define		pd2_6			pd2_addr.bit.b6		/* Port P2_6 direction register */
#define		pd2_7			pd2_addr.bit.b7		/* Port P2_7 direction register */

/*------------------------------------------------------
	Port P3 direction register
------------------------------------------------------*/
union byte_def pd3_addr;
#define		pd3				pd3_addr.byte

#define		pd3_0			pd3_addr.bit.b0		/* Port P3_0 direction register */
#define		pd3_1			pd3_addr.bit.b1		/* Port P3_1 direction register */
#define		pd3_2			pd3_addr.bit.b2		/* Port P3_2 direction register */
#define		pd3_3			pd3_addr.bit.b3		/* Port P3_3 direction register */
#define		pd3_4			pd3_addr.bit.b4		/* Port P3_4 direction register */
#define		pd3_5			pd3_addr.bit.b5		/* Port P3_5 direction register */
#define		pd3_6			pd3_addr.bit.b6		/* Port P3_6 direction register */
#define		pd3_7			pd3_addr.bit.b7		/* Port P3_7 direction register */

/*------------------------------------------------------
	Port P4 register
------------------------------------------------------*/
union byte_def p4_addr;
#define		p4				p4_addr.byte

#define		p4_0			p4_addr.bit.b0		/* Port P4_0 register */
#define		p4_1			p4_addr.bit.b1		/* Port P4_1 register */
#define		p4_2			p4_addr.bit.b2		/* Port P4_2 register */
#define		p4_3			p4_addr.bit.b3		/* Port P4_3 register */
#define		p4_4			p4_addr.bit.b4		/* Port P4_4 register */
#define		p4_5			p4_addr.bit.b5		/* Port P4_5 register */
#define		p4_6			p4_addr.bit.b6		/* Port P4_6 register */
#define		p4_7			p4_addr.bit.b7		/* Port P4_7 register */

/*------------------------------------------------------
	Port P5 register
------------------------------------------------------*/
union byte_def p5_addr;
#define		p5				p5_addr.byte

#define		p5_0			p5_addr.bit.b0		/* Port P5_0 register */
#define		p5_1			p5_addr.bit.b1		/* Port P5_1 register */
#define		p5_2			p5_addr.bit.b2		/* Port P5_2 register */
#define		p5_3			p5_addr.bit.b3		/* Port P5_3 register */
#define		p5_4			p5_addr.bit.b4		/* Port P5_4 register */
#define		p5_5			p5_addr.bit.b5		/* Port P5_5 register */
#define		p5_6			p5_addr.bit.b6		/* Port P5_6 register */
#define		p5_7			p5_addr.bit.b7		/* Port P5_7 register */

/*------------------------------------------------------
	Port P4 direction register
------------------------------------------------------*/
union byte_def pd4_addr;
#define		pd4				pd4_addr.byte

#define		pd4_0			pd4_addr.bit.b0		/* Port P4_0 direction register */
#define		pd4_1			pd4_addr.bit.b1		/* Port P4_1 direction register */
#define		pd4_2			pd4_addr.bit.b2		/* Port P4_2 direction register */
#define		pd4_3			pd4_addr.bit.b3		/* Port P4_3 direction register */
#define		pd4_4			pd4_addr.bit.b4		/* Port P4_4 direction register */
#define		pd4_5			pd4_addr.bit.b5		/* Port P4_5 direction register */
#define		pd4_6			pd4_addr.bit.b6		/* Port P4_6 direction register */
#define		pd4_7			pd4_addr.bit.b7		/* Port P4_7 direction register */

/*------------------------------------------------------
	Port P5 direction register
------------------------------------------------------*/
union byte_def pd5_addr;
#define		pd5				pd5_addr.byte

#define		pd5_0			pd5_addr.bit.b0		/* Port P5_0 direction register */
#define		pd5_1			pd5_addr.bit.b1		/* Port P5_1 direction register */
#define		pd5_2			pd5_addr.bit.b2		/* Port P5_2 direction register */
#define		pd5_3			pd5_addr.bit.b3		/* Port P5_3 direction register */
#define		pd5_4			pd5_addr.bit.b4		/* Port P5_4 direction register */
#define		pd5_5			pd5_addr.bit.b5		/* Port P5_5 direction register */
#define		pd5_6			pd5_addr.bit.b6		/* Port P5_6 direction register */
#define		pd5_7			pd5_addr.bit.b7		/* Port P5_7 direction register */

/*------------------------------------------------------
	Port P6 register
------------------------------------------------------*/
union byte_def p6_addr;
#define		p6				p6_addr.byte

#define		p6_0			p6_addr.bit.b0		/* Port P6_0 register */
#define		p6_1			p6_addr.bit.b1		/* Port P6_1 register */
#define		p6_2			p6_addr.bit.b2		/* Port P6_2 register */
#define		p6_3			p6_addr.bit.b3		/* Port P6_3 register */
#define		p6_4			p6_addr.bit.b4		/* Port P6_4 register */
#define		p6_5			p6_addr.bit.b5		/* Port P6_5 register */
#define		p6_6			p6_addr.bit.b6		/* Port P6_6 register */
#define		p6_7			p6_addr.bit.b7		/* Port P6_7 register */

/*------------------------------------------------------
	Port P7 register
------------------------------------------------------*/
union byte_def p7_addr;
#define		p7				p7_addr.byte

#define		p7_0			p7_addr.bit.b0		/* Port P7_0 register */
#define		p7_1			p7_addr.bit.b1		/* Port P7_1 register */
#define		p7_2			p7_addr.bit.b2		/* Port P7_2 register */
#define		p7_3			p7_addr.bit.b3		/* Port P7_3 register */
#define		p7_4			p7_addr.bit.b4		/* Port P7_4 register */
#define		p7_5			p7_addr.bit.b5		/* Port P7_5 register */
#define		p7_6			p7_addr.bit.b6		/* Port P7_6 register */
#define		p7_7			p7_addr.bit.b7		/* Port P7_7 register */

/*------------------------------------------------------
	Port P6 direction register
------------------------------------------------------*/
union byte_def pd6_addr;
#define		pd6				pd6_addr.byte

#define		pd6_0			pd6_addr.bit.b0		/* Port P6_0 direction register */
#define		pd6_1			pd6_addr.bit.b1		/* Port P6_1 direction register */
#define		pd6_2			pd6_addr.bit.b2		/* Port P6_2 direction register */
#define		pd6_3			pd6_addr.bit.b3		/* Port P6_3 direction register */
#define		pd6_4			pd6_addr.bit.b4		/* Port P6_4 direction register */
#define		pd6_5			pd6_addr.bit.b5		/* Port P6_5 direction register */
#define		pd6_6			pd6_addr.bit.b6		/* Port P6_6 direction register */
#define		pd6_7			pd6_addr.bit.b7		/* Port P6_7 direction register */

/*------------------------------------------------------
	Port P7 direction register
------------------------------------------------------*/
union byte_def pd7_addr;
#define		pd7				pd7_addr.byte

#define		pd7_0			pd7_addr.bit.b0		/* Port P7_0 direction register */
#define		pd7_1			pd7_addr.bit.b1		/* Port P7_1 direction register */
#define		pd7_2			pd7_addr.bit.b2		/* Port P7_2 direction register */
#define		pd7_3			pd7_addr.bit.b3		/* Port P7_3 direction register */
#define		pd7_4			pd7_addr.bit.b4		/* Port P7_4 direction register */
#define		pd7_5			pd7_addr.bit.b5		/* Port P7_5 direction register */
#define		pd7_6			pd7_addr.bit.b6		/* Port P7_6 direction register */
#define		pd7_7			pd7_addr.bit.b7		/* Port P7_7 direction register */

/*------------------------------------------------------
	Port P8 register
------------------------------------------------------*/
union byte_def p8_addr;
#define		p8				p8_addr.byte

#define		p8_0			p8_addr.bit.b0		/* Port P8_0 register */
#define		p8_1			p8_addr.bit.b1		/* Port P8_1 register */
#define		p8_2			p8_addr.bit.b2		/* Port P8_2 register */
#define		p8_3			p8_addr.bit.b3		/* Port P8_3 register */
#define		p8_4			p8_addr.bit.b4		/* Port P8_4 register */
#define		p8_5			p8_addr.bit.b5		/* Port P8_5 register */
#define		p8_6			p8_addr.bit.b6		/* Port P8_6 register */
#define		p8_7			p8_addr.bit.b7		/* Port P8_7 register */

/*------------------------------------------------------
	Port P9 register
------------------------------------------------------*/
union byte_def p9_addr;
#define		p9				p9_addr.byte

#define		p9_0			p9_addr.bit.b0		/* Port P9_0 register */
#define		p9_1			p9_addr.bit.b1		/* Port P9_1 register */
#define		p9_2			p9_addr.bit.b2		/* Port P9_2 register */
#define		p9_3			p9_addr.bit.b3		/* Port P9_3 register */
#define		p9_4			p9_addr.bit.b4		/* Port P9_4 register */
#define		p9_5			p9_addr.bit.b5		/* Port P9_5 register */
#define		p9_6			p9_addr.bit.b6		/* Port P9_6 register */
#define		p9_7			p9_addr.bit.b7		/* Port P9_7 register */

/*------------------------------------------------------
	Port P8 direction register
------------------------------------------------------*/
union byte_def pd8_addr;
#define		pd8				pd8_addr.byte

#define		pd8_0			pd8_addr.bit.b0		/* Port P8_0 direction register */
#define		pd8_1			pd8_addr.bit.b1		/* Port P8_1 direction register */
#define		pd8_2			pd8_addr.bit.b2		/* Port P8_2 direction register */
#define		pd8_3			pd8_addr.bit.b3		/* Port P8_3 direction register */
#define		pd8_4			pd8_addr.bit.b4		/* Port P8_4 direction register */
#define		pd8_6			pd8_addr.bit.b6		/* Port P8_6 direction register */
#define		pd8_7			pd8_addr.bit.b7		/* Port P8_7 direction register */

/*------------------------------------------------------
	Port P9 direction register
------------------------------------------------------*/
union byte_def pd9_addr;
#define		pd9				pd9_addr.byte

#define		pd9_0			pd9_addr.bit.b0		/* Port P9_0 direction register */
#define		pd9_1			pd9_addr.bit.b1		/* Port P9_1 direction register */
#define		pd9_2			pd9_addr.bit.b2		/* Port P9_2 direction register */
#define		pd9_3			pd9_addr.bit.b3		/* Port P9_3 direction register */
#define		pd9_4			pd9_addr.bit.b4		/* Port P9_4 direction register */
#define		pd9_5			pd9_addr.bit.b5		/* Port P9_5 direction register */
#define		pd9_6			pd9_addr.bit.b6		/* Port P9_6 direction register */
#define		pd9_7			pd9_addr.bit.b7		/* Port P9_7 direction register */

/*------------------------------------------------------
	Port P10 register
------------------------------------------------------*/
union byte_def p10_addr;
#define		p10				p10_addr.byte

#define		p10_0			p10_addr.bit.b0		/* Port P10_0 register */
#define		p10_1			p10_addr.bit.b1		/* Port P10_1 register */
#define		p10_2			p10_addr.bit.b2		/* Port P10_2 register */
#define		p10_3			p10_addr.bit.b3		/* Port P10_3 register */
#define		p10_4			p10_addr.bit.b4		/* Port P10_4 register */
#define		p10_5			p10_addr.bit.b5		/* Port P10_5 register */
#define		p10_6			p10_addr.bit.b6		/* Port P10_6 register */
#define		p10_7			p10_addr.bit.b7		/* Port P10_7 register */

/*------------------------------------------------------
	Port P11 register
------------------------------------------------------*/
union byte_def p11_addr;
#define		p11				p11_addr.byte

#define		p11_0			p11_addr.bit.b0		/* Port P11_0 register */
#define		p11_1			p11_addr.bit.b1		/* Port P11_1 register */
#define		p11_2			p11_addr.bit.b2		/* Port P11_2 register */
#define		p11_3			p11_addr.bit.b3		/* Port P11_3 register */
#define		p11_4			p11_addr.bit.b4		/* Port P11_4 register */
#define		p11_5			p11_addr.bit.b5		/* Port P11_5 register */
#define		p11_6			p11_addr.bit.b6		/* Port P11_6 register */
#define		p11_7			p11_addr.bit.b7		/* Port P11_7 register */

/*------------------------------------------------------
	Port P10 direction register
------------------------------------------------------*/
union byte_def pd10_addr;
#define		pd10			pd10_addr.byte

#define		pd10_0			pd10_addr.bit.b0	/* Port P10_0 direction register */
#define		pd10_1			pd10_addr.bit.b1	/* Port P10_1 direction register */
#define		pd10_2			pd10_addr.bit.b2	/* Port P10_2 direction register */
#define		pd10_3			pd10_addr.bit.b3	/* Port P10_3 direction register */
#define		pd10_4			pd10_addr.bit.b4	/* Port P10_4 direction register */
#define		pd10_5			pd10_addr.bit.b5	/* Port P10_5 direction register */
#define		pd10_6			pd10_addr.bit.b6	/* Port P10_6 direction register */
#define		pd10_7			pd10_addr.bit.b7	/* Port P10_7 direction register */

/*------------------------------------------------------
	Port P11 direction register
------------------------------------------------------*/
union byte_def pd11_addr;
#define		pd11			pd11_addr.byte

#define		pd11_0			pd11_addr.bit.b0	/* Port P11_0 direction register */
#define		pd11_1			pd11_addr.bit.b1	/* Port P11_1 direction register */
#define		pd11_2			pd11_addr.bit.b2	/* Port P11_2 direction register */
#define		pd11_3			pd11_addr.bit.b3	/* Port P11_3 direction register */
#define		pd11_4			pd11_addr.bit.b4	/* Port P11_4 direction register */
#define		pd11_5			pd11_addr.bit.b5	/* Port P11_5 direction register */
#define		pd11_6			pd11_addr.bit.b6	/* Port P11_6 direction register */
#define		pd11_7			pd11_addr.bit.b7	/* Port P11_7 direction register */

/*------------------------------------------------------
	Port P12 register
------------------------------------------------------*/
union byte_def p12_addr;
#define		p12				p12_addr.byte

#define		p12_0			p12_addr.bit.b0		/* Port P12_0 register */
#define		p12_1			p12_addr.bit.b1		/* Port P12_1 register */
#define		p12_2			p12_addr.bit.b2		/* Port P12_2 register */
#define		p12_3			p12_addr.bit.b3		/* Port P12_3 register */
#define		p12_4			p12_addr.bit.b4		/* Port P12_4 register */
#define		p12_5			p12_addr.bit.b5		/* Port P12_5 register */
#define		p12_6			p12_addr.bit.b6		/* Port P12_6 register */
#define		p12_7			p12_addr.bit.b7		/* Port P12_7 register */

/*------------------------------------------------------
	Port P13 register
------------------------------------------------------*/
union byte_def p13_addr;
#define		p13				p13_addr.byte

#define		p13_0			p13_addr.bit.b0		/* Port P13_0 register */
#define		p13_1			p13_addr.bit.b1		/* Port P13_1 register */
#define		p13_2			p13_addr.bit.b2		/* Port P13_2 register */
#define		p13_3			p13_addr.bit.b3		/* Port P13_3 register */
#define		p13_4			p13_addr.bit.b4		/* Port P13_4 register */
#define		p13_5			p13_addr.bit.b5		/* Port P13_5 register */
#define		p13_6			p13_addr.bit.b6		/* Port P13_6 register */
#define		p13_7			p13_addr.bit.b7		/* Port P13_7 register */

/*------------------------------------------------------
	Port P12 direction register
------------------------------------------------------*/
union byte_def pd12_addr;
#define		pd12			pd12_addr.byte

#define		pd12_0			pd12_addr.bit.b0	/* Port P12_0 direction register */
#define		pd12_1			pd12_addr.bit.b1	/* Port P12_1 direction register */
#define		pd12_2			pd12_addr.bit.b2	/* Port P12_2 direction register */
#define		pd12_3			pd12_addr.bit.b3	/* Port P12_3 direction register */
#define		pd12_4			pd12_addr.bit.b4	/* Port P12_4 direction register */
#define		pd12_5			pd12_addr.bit.b5	/* Port P12_5 direction register */
#define		pd12_6			pd12_addr.bit.b6	/* Port P12_6 direction register */
#define		pd12_7			pd12_addr.bit.b7	/* Port P12_7 direction register */

/*------------------------------------------------------
	Port P13 direction register
------------------------------------------------------*/
union byte_def pd13_addr;
#define		pd13			pd13_addr.byte

#define		pd13_0			pd13_addr.bit.b0	/* Port P13_0 direction register */
#define		pd13_1			pd13_addr.bit.b1	/* Port P13_1 direction register */
#define		pd13_2			pd13_addr.bit.b2	/* Port P13_2 direction register */
#define		pd13_3			pd13_addr.bit.b3	/* Port P13_3 direction register */
#define		pd13_4			pd13_addr.bit.b4	/* Port P13_4 direction register */
#define		pd13_5			pd13_addr.bit.b5	/* Port P13_5 direction register */
#define		pd13_6			pd13_addr.bit.b6	/* Port P13_6 direction register */
#define		pd13_7			pd13_addr.bit.b7	/* Port P13_7 direction register */

/*------------------------------------------------------
	Pull-up control register 0
------------------------------------------------------*/
union byte_def pur0_addr;
#define		pur0			pur0_addr.byte

#define		pu00			pur0_addr.bit.b0	/* P0_0 to P0_3 pull-up */
#define		pu01			pur0_addr.bit.b1	/* P0_4 to P0_7 pull-up */
#define		pu02			pur0_addr.bit.b2	/* P1_0 to P1_3 pull-up */
#define		pu03			pur0_addr.bit.b3	/* P1_4 to P1_7 pull-up */
#define		pu04			pur0_addr.bit.b4	/* P2_0 to P2_3 pull-up */
#define		pu05			pur0_addr.bit.b5	/* P2_4 to P2_7 pull-up */
#define		pu06			pur0_addr.bit.b6	/* P3_0 to P3_3 pull-up */
#define		pu07			pur0_addr.bit.b7	/* P3_4 to P3_7 pull-up */

/*------------------------------------------------------
	Pull-up control register 1
------------------------------------------------------*/
union byte_def pur1_addr;
#define		pur1			pur1_addr.byte

#define		pu10			pur1_addr.bit.b0	/* P4_0 to P4_3 pull-up */
#define		pu11			pur1_addr.bit.b1	/* P4_4 to P4_7 pull-up */
#define		pu12			pur1_addr.bit.b2	/* P5_0 to P5_3 pull-up */
#define		pu13			pur1_addr.bit.b3	/* P5_4 to P5_7 pull-up */
#define		pu14			pur1_addr.bit.b4	/* P6_0 to P6_3 pull-up */
#define		pu15			pur1_addr.bit.b5	/* P6_4 to P6_7 pull-up */
#define		pu16			pur1_addr.bit.b6	/* P7_0 to P7_3 pull-up (Except P7_0,P7_1 ; P7_0,P7_1->N-channel open drain ports) */
#define		pu17			pur1_addr.bit.b7	/* P7_4 to P7_7 pull-up */

/*------------------------------------------------------
	Pull-up control register 2
------------------------------------------------------*/
union byte_def pur2_addr;
#define		pur2			pur2_addr.byte

#define		pu20			pur2_addr.bit.b0	/* P8_0 to P8_3 pull-up */
#define		pu21			pur2_addr.bit.b1	/* P8_4 to P8_7 pull-up (Except P8_5) */
#define		pu22			pur2_addr.bit.b2	/* P9_0 to P9_3 pull-up */
#define		pu23			pur2_addr.bit.b3	/* P9_4 to P9_7 pull-up */
#define		pu24			pur2_addr.bit.b4	/* P10_0 to P10_3 pull-up */
#define		pu25			pur2_addr.bit.b5	/* P10_4 to P10_7 pull-up */

/*------------------------------------------------------
	Port control register
------------------------------------------------------*/
union byte_def pcr_addr;
#define		pcr				pcr_addr.byte

#define		pcr0			pcr_addr.bit.b0		/* Port P1 control register */

/********************************************************
*	declare SFR union									*
********************************************************/
union{
	struct{
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
		char	b8:1;
		char	b9:1;
		char	b10:1;
		char	b11:1;
		char	b12:1;
		char	b13:1;
		char	b14:1;
		char	b15:1;
	}bit;
	struct{
		char	low;							/* low	8 bit */
		char	high;							/* high 8 bit */
	}byte;
	unsigned short	word;
}tcr0_addr,tcr1_addr,
 u0tb_addr,u1tb_addr,u2tb_addr,u0rb_addr,u1rb_addr,u2rb_addr,
 crcd_addr,
 ad0_addr,ad1_addr,ad2_addr,ad3_addr,ad4_addr,ad5_addr,ad6_addr,ad7_addr;

/*------------------------------------------------------
	 DMA0 transfer counter 16 bit
------------------------------------------------------*/
#define		tcr0		tcr0_addr.word
#define		tcr0l		tcr0_addr.byte.low		/* DMA0 transfer counter low  8 bit */
#define		tcr0h		tcr0_addr.byte.high		/* DMA0 transfer counter high 8 bit */

/*------------------------------------------------------
	 DMA1 transfer counter 16 bit
------------------------------------------------------*/
#define		tcr1		tcr1_addr.word
#define		tcr1l		tcr1_addr.byte.low		/* DMA1 transfer counter low  8 bit */
#define		tcr1h		tcr1_addr.byte.high		/* DMA1 transfer counter high 8 bit */

/*------------------------------------------------------
	UART0 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
#define		u0tb		u0tb_addr.word
#define		u0tbl		u0tb_addr.byte.low		/* UART0 Transmit buffer register low  8 bit */
#define		u0tbh		u0tb_addr.byte.high		/* UART0 Transmit buffer register high 8 bit */

/*------------------------------------------------------
	UART Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
#define		u1tb		u1tb_addr.word
#define		u1tbl		u1tb_addr.byte.low		/* UART1 Transmit buffer register low  8 bit */
#define		u1tbh		u1tb_addr.byte.high		/* UART1 Transmit buffer register high 8 bit */

/*------------------------------------------------------
	UART2 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
#define		u2tb		u2tb_addr.word
#define		u2tbl		u2tb_addr.byte.low		/* UART2 Transmit buffer register low  8 bit */
#define		u2tbh		u2tb_addr.byte.high		/* UART2 Transmit buffer register high 8 bit */

/*------------------------------------------------------
	UART0 receive buffer register
------------------------------------------------------*/
#define		u0rb		u0rb_addr.word
#define		u0rbl		u0rb_addr.byte.low		/* UART0 receive buffer register low  8 bit */
#define		u0rbh		u0rb_addr.byte.high		/* UART0 receive buffer register high 8 bit */

#define		abt_u0rb	u0rb_addr.bit.b11		/* Arbitration lost detecting flag */
#define		oer_u0rb	u0rb_addr.bit.b12		/* Overrun error flag */
#define		fer_u0rb	u0rb_addr.bit.b13		/* Framing error flag*/
#define		per_u0rb	u0rb_addr.bit.b14		/* Parity error flag */
#define		sum_u0rb	u0rb_addr.bit.b15		/* Error sum flag */

/*------------------------------------------------------
	UART1 receive buffer register
------------------------------------------------------*/
#define		u1rb		u1rb_addr.word
#define		u1rbl		u1rb_addr.byte.low		/* UART1 receive buffer register low  8 bit */
#define		u1rbh		u1rb_addr.byte.high		/* UART1 receive buffer register high 8 bit */

#define		abt_u1rb	u1rb_addr.bit.b11		/* Arbitration lost detecting flag */
#define		oer_u1rb	u1rb_addr.bit.b12		/* Overrun error flag */
#define		fer_u1rb	u1rb_addr.bit.b13		/* Framing error flag*/
#define		per_u1rb	u1rb_addr.bit.b14		/* Parity error flag */
#define		sum_u1rb	u1rb_addr.bit.b15		/* Error sum flag */

/*------------------------------------------------------
	UART2 receive buffer register
------------------------------------------------------*/
#define		u2rb		u2rb_addr.word
#define		u2rbl		u2rb_addr.byte.low		/* UART2 receive buffer register low  8 bit */
#define		u2rbh		u2rb_addr.byte.high		/* UART2 receive buffer register high 8 bit */

#define		abt_u2rb	u2rb_addr.bit.b11		/* Arbitration lost detecting flag */
#define		abt_u2rb	u2rb_addr.bit.b11		/* Arbitration lost detecting flag */
#define		oer_u2rb	u2rb_addr.bit.b12		/* Overrun error flag */
#define		fer_u2rb	u2rb_addr.bit.b13		/* Framing error flag*/
#define		per_u2rb	u2rb_addr.bit.b14		/* Parity error flag */
#define		sum_u2rb	u2rb_addr.bit.b15		/* Error sum flag */

/*------------------------------------------------------
	 CRC data register 16 bit
------------------------------------------------------*/
#define		crcd		crcd_addr.word
#define		crcdl		crcd_addr.byte.low		/* CRC data register low  8 bit */
#define		crcdh		crcd_addr.byte.high		/* CRC data register high 8 bit */

/*------------------------------------------------------
	 A-D register 0 16 bit
------------------------------------------------------*/
#define		ad0			ad0_addr.word
#define		ad0l		ad0_addr.byte.low		/* A-D register 0 low  8 bit */
#define		ad0h		ad0_addr.byte.high		/* A-D register 0 high 8 bit */

/*------------------------------------------------------
	 A-D register 1 16 bit
------------------------------------------------------*/
#define		ad1			ad1_addr.word
#define		ad1l		ad1_addr.byte.low		/* A-D register 1 low  8 bit */
#define		ad1h		ad1_addr.byte.high		/* A-D register 1 high 8 bit */

/*------------------------------------------------------
	 A-D register 2 16 bit
------------------------------------------------------*/
#define		ad2			ad2_addr.word
#define		ad2l		ad2_addr.byte.low		/* A-D register 2 low  8 bit */
#define		ad2h		ad2_addr.byte.high		/* A-D register 2 high 8 bit */

/*------------------------------------------------------
	 A-D register 3 16 bit
------------------------------------------------------*/
#define		ad3			ad3_addr.word
#define		ad3l		ad3_addr.byte.low		/* A-D register 3 low  8 bit */
#define		ad3h		ad3_addr.byte.high		/* A-D register 3 high 8 bit */

/*------------------------------------------------------
	 A-D register 4 16 bit
------------------------------------------------------*/
#define		ad4			ad4_addr.word
#define		ad4l		ad4_addr.byte.low		/* A-D register 4 low  8 bit */
#define		ad4h		ad4_addr.byte.high		/* A-D register 4 high 8 bit */

/*------------------------------------------------------
	 A-D register 5 16 bit
------------------------------------------------------*/
#define		ad5			ad5_addr.word
#define		ad5l		ad5_addr.byte.low		/* A-D register 5 low  8 bit */
#define		ad5h		ad5_addr.byte.high		/* A-D register 5 high 8 bit */

/*------------------------------------------------------
	 A-D register 6 16 bit
------------------------------------------------------*/
#define		ad6			ad6_addr.word
#define		ad6l		ad6_addr.byte.low		/* A-D register 6 low  8 bit */
#define		ad6h		ad6_addr.byte.high		/* A-D register 6 high 8 bit */

/*------------------------------------------------------
	 A-D register 7 16 bit
------------------------------------------------------*/
#define		ad7			ad7_addr.word
#define		ad7l		ad7_addr.byte.low		/* A-D register 7 low  8 bit */
#define		ad7h		ad7_addr.byte.high		/* A-D register 7 high 8 bit */

/********************************************************
*	declare SFR union									*
********************************************************/
union{
	struct{
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
		char	b8:1;
		char	b9:1;
		char	b10:1;
		char	b11:1;
		char	b12:1;
		char	b13:1;
		char	b14:1;
		char	b15:1;
		char	b16:1;
		char	b17:1;
		char	b18:1;
		char	b19:1;
	}bit;
	struct{
		char	low;							/* low	8 bit */
		char	mid;							/* mid	8 bit */
		char	high;							/* high 8 bit */
		char	nc;								/* non use */
	}byte;
	unsigned long	dword;
}rmad0_addr,rmad1_addr,rmad2_addr,rmad3_addr,
 sar0_addr,sar1_addr,
 dar0_addr,dar1_addr;

/*------------------------------------------------------
	 Address match interrupt register 0 32 bit
------------------------------------------------------*/
#define		rmad0		rmad0_addr.dword
#define		rmad0l		rmad0_addr.byte.low		/* Address match interrupt register 0 low  8 bit */
#define		rmad0m		rmad0_addr.byte.mid		/* Address match interrupt register 0 mid  8 bit */
#define		rmad0h		rmad0_addr.byte.high	/* Address match interrupt register 0 high 8 bit */

/*------------------------------------------------------
	 Address match interrupt register 1 32 bit
------------------------------------------------------*/
#define		rmad1		rmad1_addr.dword
#define		rmad1l		rmad1_addr.byte.low		/* Address match interrupt register 1 low  8 bit */
#define		rmad1m		rmad1_addr.byte.mid		/* Address match interrupt register 1 mid  8 bit */
#define		rmad1h		rmad1_addr.byte.high	/* Address match interrupt register 1 high 8 bit */

/*------------------------------------------------------
	 Address match interrupt register 2 32 bit
------------------------------------------------------*/
#define		rmad2		rmad2_addr.dword
#define		rmad2l		rmad2_addr.byte.low		/* Address match interrupt register 2 low  8 bit */
#define		rmad2m		rmad2_addr.byte.mid		/* Address match interrupt register 2 mid  8 bit */
#define		rmad2h		rmad2_addr.byte.high	/* Address match interrupt register 2 high 8 bit */

/*------------------------------------------------------
	 Address match interrupt register 3 32 bit
------------------------------------------------------*/
#define		rmad3		rmad3_addr.dword
#define		rmad3l		rmad3_addr.byte.low		/* Address match interrupt register 3 low  8 bit */
#define		rmad3m		rmad3_addr.byte.mid		/* Address match interrupt register 3 mid  8 bit */
#define		rmad3h		rmad3_addr.byte.high	/* Address match interrupt register 3 high 8 bit */

/*------------------------------------------------------
	 DMA0 source pointer 32 bit
------------------------------------------------------*/
#define		sar0		sar0_addr.dword
#define		sar0l		sar0_addr.byte.low		/* DMA0 source pointer low	8 bit */
#define		sar0m		sar0_addr.byte.mid		/* DMA0 source pointer mid	8 bit */
#define		sar0h		sar0_addr.byte.high		/* DMA0 source pointer high 8 bit */

/*------------------------------------------------------
	 DMA1 source pointer 32 bit
------------------------------------------------------*/
#define		sar1		sar1_addr.dword
#define		sar1l		sar1_addr.byte.low		/* DMA1 source pointer low	8 bit */
#define		sar1m		sar1_addr.byte.mid		/* DMA1 source pointer mid	8 bit */
#define		sar1h		sar1_addr.byte.high		/* DMA1 source pointer high 8 bit */

/*------------------------------------------------------
	 DMA0 destination pointer 32 bit
------------------------------------------------------*/
#define		dar0		dar0_addr.dword
#define		dar0l		dar0_addr.byte.low		/* DMA0 destination pointer low	 8 bit */
#define		dar0m		dar0_addr.byte.mid		/* DMA0 destination pointer mid	 8 bit */
#define		dar0h		dar0_addr.byte.high		/* DMA0 destination pointer high 8 bit */

/*------------------------------------------------------
	 DMA1 destination pointer 32 bit
------------------------------------------------------*/
#define		dar1		dar1_addr.dword
#define		dar1l		dar1_addr.byte.low		/* DMA1 destination pointer low	 8 bit */
#define		dar1m		dar1_addr.byte.mid		/* DMA1 destination pointer mid	 8 bit */
#define		dar1h		dar1_addr.byte.high		/* DMA1 destination pointer high 8 bit */

#endif /* SFR62P_H */
