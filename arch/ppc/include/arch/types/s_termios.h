struct termios {
	tcflag_t	c_iflag;	// input mode flags
	tcflag_t	c_oflag;	// output mode flags
	tcflag_t	c_cflag;	// control mode flags
	tcflag_t	c_lflag;	// local mode flags
	cc_t		c_cc[NCCS];	// control characters
	cc_t		c_line;		// line discipline (== c_cc[19])
	speed_t		c_ispeed;	// input speed
	speed_t		c_ospeed;	// output speed
};
