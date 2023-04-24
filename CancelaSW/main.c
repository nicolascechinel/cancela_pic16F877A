//******************************************************************************
//***** Program didatico CANCELA  **********************************************
//***** Desenvolvido por: Nicolas Cechinel, Victor Camargo ***************************************

#include <16F877A.h>

#FUSES XT,NOWDT,PUT,NOBROWNOUT,NOLVP,NOCPD,NOWRT

#use delay(clock=4000000)

void stand_by()
{
   output_high(PIN_D0); // LED ABRINDO OFF
   output_high(PIN_D1); // LED FECHANDO OFF
   output_low(PIN_D2);  // MCA LOW
   output_low(PIN_D3);  // MCF LOW
   return;
}

void open()
{
   output_low(PIN_D0);  // LED ABRINDO ON
   output_high(PIN_D1); // LED FECHANDO OFF
   output_high(PIN_D2); // MCA HIGH
   output_low(PIN_D3);  // MCF LOW
   return;
}

void close()
{
   output_high(PIN_D0); // LED ABRINDO OFF
   output_low(PIN_D1);  // LED FECHANDO ON
   output_low(PIN_D2);  // MCA LOW
   output_high(PIN_D3); // MCF HIGH
   return;
}


#int_ext // Trata interrupcao externa 
void trata_ext() // acionada pelo sensor ST
{
   output_high(PIN_D4);  // BUZZER HIGH
   
   if((input(pin_b1) == 0) && (input(pin_b2) == 0))   // TESTA SE TEM CARRO E A CANCELA ESTA ABERTA
   {
      delay_ms(20000);   // Conta 10 seg
      while (input(pin_b3) == 1) close(); // FECHA CANCELA ATÉ FIM DE CURSO
      stand_by(); // APAGA LEDS E DESLIGA MOTORES
   }
   else
   {
      while (input(pin_b3) == 1) close(); // FECHA CANCELA ATÉ FIM DE CURSO
      stand_by(); // APAGA LEDS E DESLIGA MOTORES
      delay_ms(20000);   // Conta 10 seg
   }
   return;
}

void main()
{
   Port_b_pullups(true);    //habilita os resistores internos de pull ups
   
   // HABILITA INTERRUPCOES
   enable_interrupts(global | int_ext);
   
   int1 ST, SA, SCA, SCF;  // INPUT SENSORS
   
   while (input(pin_b3) == 1) close(); // INICIA COM CANCELA FECHADA
   
   while(TRUE)
   {
      stand_by(); // APAGA LEDS E DESLIGA MOTORES
      output_low(PIN_D4);  // BUZZER LOW
      
      // Entradas do sistema
      ST = input(pin_b0);  // Sensor trem
      SA = input(pin_b1);  // Sensor automovel 
      SCA = input(pin_b2); // Sensor de fim de curso cancela aberta
      SCF = input(pin_b3); // Sensor de fim de curso cancela fechada
      
      if (SA == 0)
      {
         while (input(pin_b2) == 1) open(); // ABRE CANCELA ATÉ FIM DE CURSO
         
         stand_by(); // APAGA LEDS E DESLIGA MOTORES
         
         delay_ms(20000);   // Conta 10 seg
         
         while (input(pin_b3) == 1) close(); // FECHA CANCELA ATÉ FIM DE CURSO
      }
   }
}
