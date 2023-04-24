# cancela_pic16F877A
sistema embarcado utilizando o pic16F877A e sensores e atuadores para controlar uma passagem de nível(cancela de trem). 

Desenvolver um sistema embarcado(hardware e software) para controlar uma passagem de nível(cancela de trem). O sistema deverá manter a cancela sempre fechada e quando um carro se aproximar ela deverá abrir automaticamente. No caso de existir carro e um trem estiver por passando a cancela não poderá abrir. Se estiver aberta deve aguardar um tempo para o carro passar e depois fechar devido ao trem que está chegando.(usar interrupção para o sinal do trem).
SA:Sensor de presença de automóvel
ST:Sensor de presença de trem
SCF: Sensor cancela fechada
SCA: Sensor cancela aberta
MCA: Motor da cancela Abrindo
MCF: Motot da cancela fechando
Abrindo: Luz indicativa de sistema abrido
Fechando:Luz indicativa de sistema fechando

