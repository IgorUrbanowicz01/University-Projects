package com.example.w01java;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import java.util.Random;

public class MainActivity extends AppCompatActivity {
    private int score = 0;
    private int r1 = 0;
    private int r2 = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        score = 0;
        roll();
    }

    private void roll(){
        TextView pointsTextView = findViewById(R.id.points);
        pointsTextView.setText("Punkty: " + score);

        Random random = new Random();
        r1 = random.nextInt(10);
        r2 = random.nextInt(10);

        Button leftClickButton = findViewById(R.id.leftClick);
        leftClickButton.setText("" + r1);

        Button rightClickButton = findViewById(R.id.rightClick);
        rightClickButton.setText("" + r2);
    }

    public void buttonClickRight(View view) {
        if(r2>=r1){
            score++;
            Toast.makeText(this, "Super", Toast.LENGTH_SHORT).show();
        }else{
            score--;
            Toast.makeText(this, "Słabiutko", Toast.LENGTH_SHORT).show();
        }
        roll();
    }

    public void buttonClickLeft(View view) {
        if(r1>=r2){
            score++;
            Toast.makeText(this, "Super", Toast.LENGTH_SHORT).show();
        }else{
            score--;
            Toast.makeText(this, "Słabiutko", Toast.LENGTH_SHORT).show();
        }
        roll();
    }
}