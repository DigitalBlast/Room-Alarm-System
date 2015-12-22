#include <Wire.h>

#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd (0x27, 16, 2);

bool systemRunning = false ;

bool caught = false;

int letterStatus1;

int letterStatus2;

int letterStatus3;

int letterStatus4;

char header1[] = { "Status:" };

char message1[] = { "NORMAL" };

char message2[] = { "ARMED" };

char message3[] = { "WARNING" };

void setup() {
  pinMode( 4, OUTPUT );

  pinMode( 7, OUTPUT );

  pinMode( 8, OUTPUT );

  pinMode( 2, OUTPUT );

  digitalWrite( 4, HIGH );

  lcd.begin( );
}

void loop() {
  if( systemRunning ) {
    digitalWrite( 4, LOW ); //Turn green off
    if( caught != true ) {
     digitalWrite( 8, HIGH ); //Turn red on
    }
    lcd.clear( );
    for ( letterStatus1 = 0; letterStatus1 <= 6; letterStatus1++ ) {
      lcd.setCursor( letterStatus1, 0 );
  
      lcd.print( header1[ letterStatus1 ] );
    }

    for ( letterStatus2 = 0; letterStatus2 <= 4; letterStatus2++ ) {
      lcd.setCursor( letterStatus2, 1 );
  
      lcd.print( message2[ letterStatus2 ] );
    }
  } else {
    digitalWrite( 8, LOW );

    digitalWrite( 4, HIGH );
    lcd.clear( );
    for ( letterStatus1 = 0; letterStatus1 <= 6; letterStatus1++ ) {
      lcd.setCursor( letterStatus1, 0 );
  
      lcd.print( header1[ letterStatus1 ] );
    }

    for ( letterStatus3 = 0; letterStatus3 <= 5; letterStatus3++ ) {
      lcd.setCursor( letterStatus3, 1 );
  
      lcd.print( message1[ letterStatus3 ] );
    }
  }

  if( caught ) { //Check to see if system has been broken
    digitalWrite( 7, HIGH ); //Fire alarm

    digitalWrite( 8, LOW ); //Turn red led off

    digitalWrite( 2, HIGH ); //Turn blue led on

    lcd.clear( );
    for ( letterStatus1 = 0; letterStatus1 <= 6; letterStatus1++ ) {
      lcd.setCursor( letterStatus1, 0 );
  
      lcd.print( header1[ letterStatus1 ] );
    }

    for ( letterStatus4 = 0; letterStatus4 <= 6; letterStatus4++ ) {
      lcd.setCursor( letterStatus4, 1 );
  
      lcd.print( message3[ letterStatus4 ] );
    }
  }
  delay( 500 );
}
