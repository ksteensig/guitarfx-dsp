IODIR1		.set 0x001C06
IODATAOUT1	.set 0x001C0A
			.global _led_blue_off
			.text

_led_blue_off:
	or 0010000000000000b, port(#IODIR1)
	and	0010000000000000b, port(#IODATAOUT1)s
	RET
