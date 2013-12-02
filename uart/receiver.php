<?php
if ($argc<2) {
	print 'specify device file' . PHP_EOL;
	exit (1);
}
try {
	$port = new SerialPort($argv[1]);
	$port->setBaudRate(2400);
	$port->setNumOfStopBits(SerialPort::STOP_BITS_2_0);
	$port->setFlowControl(SerialPort::FLOW_CONTROL_NONE);
	$port->setCanonical(false)
		->setVTime(1)->setVMin(128);
	while (true) {
		$data = $port->read(128);
		var_dump($data);
	}
} catch (Exception $e) {
	print 'exception occurred' . PHP_EOL;
	print $e->getMessage();
	exit (2);
}

