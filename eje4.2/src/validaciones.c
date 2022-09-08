int validarCelcius(int numero){
 int tipoTemperatura;
	if (numero > 1 && numero < 100){
		tipoTemperatura = 0;
	}else {
		tipoTemperatura = -1;
	}
return tipoTemperatura;
}


int validarFarenheit(int numero){
	 int tipoTemperatura;
		if (numero >= 32 && numero <= 212){
			tipoTemperatura = 0;
		}else {
			tipoTemperatura = -1;
		}
	return tipoTemperatura;
	}



