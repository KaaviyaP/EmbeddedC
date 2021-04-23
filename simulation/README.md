# Activity 1 In Action

|OFF|OFF|OFF|ON|
|:--:|:--:|:--:|:--:|
|![OFF](https://user-images.githubusercontent.com/80662569/115880845-cb579200-a468-11eb-8c5f-c0a4af578e13.PNG) |![OFF](https://user-images.githubusercontent.com/80662569/115880893-d5799080-a468-11eb-9b5c-994641382343.PNG)|![OFF](https://user-images.githubusercontent.com/80662569/115880899-d6aabd80-a468-11eb-96f0-ede2b16d1dfb.PNG)|![ON](https://user-images.githubusercontent.com/80662569/115880895-d6122700-a468-11eb-9f96-7bf86424943e.PNG)|


## Code 
```
	for(;;)
	{
        change_led_state(HIGH);
		delay_ms(LED_ON_TIME);
        change_led_state(LOW);
		delay_ms(LED_OFF_TIME);	
	}
```
