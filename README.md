# IFGAccess - Sistema de Controle de Acesso Web com RFID

## 📋 Resumo do Projeto

Este repositório contém os códigos desenvolvidos como parte do **Programa de Iniciação Científica (PIBIT) do Instituto Federal de Goiás**. O projeto IFGAccess é um sistema inteligente de controle de acesso que integra tecnologia RFID com microcontroladores ESP8266 para criar uma solução web moderna e escalável.

## 🎯 Objetivos

- Desenvolver um sistema automatizado de controle de acesso baseado em identificação RFID
- Integrar microcontroladores ESP8266 com uma plataforma web para gerenciamento remoto
- Criar protótipos funcionais com componentes Arduino para validação conceitual
- Demonstrar aplicação prática de IoT em contextos de controle de segurança e acesso

## 📅 Período de Execução

**Agosto/2018 a Julho/2019**

## 👥 Equipe

- **Professor Orientador**: Mario Teixeira Lemes
- **Aluna Pesquisadora**: Daniele dos Santos Araújo

## 🛠️ Tecnologias Utilizadas

- **Microcontroladores**: Arduino, ESP8266 (ESP-01)
- **Sensores e Módulos**:
  - Módulo RFID (leitura de cartões)
  - Sensor de Distância HC-SR04
  - Sensor de Temperatura (DHT11)
  - Sensor de Luz
  - LCD (exibição de informações)
  - Buzzer (alarme sonoro)
- **Linguagem**: Arduino C/C++
- **Plataforma Web**: ESP8266 com servidor web incorporado

## 📁 Estrutura do Repositório

```
pibit-ifgaccess/
├── conhecendo-o-arduino-parte-I/
│   └── Projetos fundamentais com Arduino (6 lições)
│       ├── Blink, Protoboard, Leitura de botões
│       ├── Entrada analógica, Controle de intensidade
│       └── Interrupções
│
├── conhecendo-o-arduino-parte-II/
│   └── Projetos intermediários (7 lições)
│       ├── Buzzer, Sensor de luz, Temperatura
│       ├── Módulo DHT11, Sensor de distância HC-SR04
│       └── Projetos com LCD
│
├── desafios-arduino/
│   └── Projetos avançados e desafios práticos (9 desafios)
│       ├── Detecção de presença e incêndio
│       ├── Detecção noturna, Alarmes
│       ├── Medição de umidade
│       └── Desafio final integrador
│
├── exemplos/
│   ├── acesso_rfid/
│   ├── esp8266/
│   │   ├── Página web de teste
│   │   └── Código principal do ESP8266
│   └── rfid/
│       └── Exemplos de controle de acesso RFID
│
├── prototipo-fisico/
│   └── ifgaccess.fzz (esquema Fritzing)
│
├── banco-de-dados/
│   └── Arquivos de banco de dados
│
└── README.md (este arquivo)
```

## 🚀 Como Começar

### Pré-requisitos

- Arduino IDE instalada ([download](https://www.arduino.cc/en/software))
- Bibliotecas Arduino necessárias:
  - SPI
  - Wire
  - EEPROM
  - Outros conforme especificado em cada projeto

### Instalação

1. Clone o repositório:

   ```bash
   git clone https://github.com/seu-usuario/pibit-ifgaccess.git
   cd pibit-ifgaccess
   ```

2. Abra o Arduino IDE

3. Carregue o exemplo desejado da respectiva pasta

4. Configure a placa e porta COM:
   - **Ferramentas** → **Placa** (selecione Arduino ou ESP8266)
   - **Ferramentas** → **Porta** (selecione a porta COM)

## 📚 Guia de Uso

### Para Iniciantes

Comece com a pasta `conhecendo-o-arduino-parte-I` para aprender conceitos fundamentais:

- Experimentos com LEDs e botões
- Entrada e saída digital/analógica
- Uso de interrupções

### Para Usuários Intermediários

Siga com `conhecendo-o-arduino-parte-II`:

- Integração de sensores (temperatura, luz, distância)
- Uso de displays LCD
- Trabalho com módulos especializados

### Para Projeto Completo

Veja `desafios-arduino` e `exemplos`:

- Projetos integrados com múltiplos sensores
- Sistemas de alarme e detecção
- Implementação de controle de acesso RFID
- Integração web com ESP8266

## 🔌 Hardware Necessário

### Componentes Principais

- Arduino Uno (recomendado para prototipagem)
- ESP8266 (ESP-01) para interface web
- Módulo RFID-RC522
- Sensor HC-SR04 (distância)
- Sensor DHT11 (temperatura e umidade)
- Sensor de luz
- Display LCD 16x2
- Buzzer
- LEDs, botões, resistores, etc.

### Ferramentas

- Protoboard
- Cabo USB para Arduino
- Cabos jumper

## 📖 Documentação

Cada pasta de projeto contém um `README.md` específico (quando aplicável) com detalhes sobre:

- Componentes utilizados
- Diagrama de ligação
- Funcionamento do código
- Possíveis melhorias

Consulte o arquivo **[prototipo-fisico/](prototipo-fisico/)** para visualizar o esquema em Fritzing.

## 🐛 Troubleshooting

### Placa não é reconhecida

- Verifique os drivers USB
- Tente uma porta COM diferente
- Reinicie o Arduino IDE

### Código não compila

- Verifique se todas as bibliotecas estão instaladas
- Confirme a placa selecionada está correta
- Procure mensagens de erro específicas na documentação do código

## 📝 Licença

Este projeto est à disposição conforme a [licença](LICENSE) especificada no repositório.

## 📧 Contato e Contribuições

Para dúvidas, sugestões ou contribuições:

- Abra uma **Issue** para reportar problemas
- Crie um **Pull Request** para sugerir melhorias
- Entre em contato com a equipe do projeto

---

**Instituto Federal de Goiás - Campus Formosa**  
_Desenvolvido com dedicação ao ensino de IoT e Microcontroladores_
