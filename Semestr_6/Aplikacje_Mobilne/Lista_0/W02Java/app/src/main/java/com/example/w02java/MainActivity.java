package com.example.w02java;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import kotlin.random.Random;

public class MainActivity extends AppCompatActivity {
    private int tem1 = 0;
    private int tem2 = 0;
    private ImageView cpuChoice;
    private ImageView playerChoice;
    private TextView result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        result = findViewById(R.id.resoult);
        cpuChoice = findViewById(R.id.cpuChoise);
        playerChoice = findViewById(R.id.yourChoise);
    }

    public int roll(){
        tem1 = Random.Default.nextInt(3);
        switch (tem1){
            case 0:
                cpuChoice.setImageResource(R.drawable.rock);
                break;
            case 1:
                cpuChoice.setImageResource(R.drawable.paper);
                break;
            case 2:
                cpuChoice.setImageResource(R.drawable.scissors);
                break;
        }
        return tem1;
    }

    public void choosePaper(View view) {
        playerChoice.setImageResource(R.drawable.paper);
        tem2 = roll();
        switch(tem2){
            case 0:
                result.setText("You Win !!!");
                break;
            case 1:
                result.setText("Tie");
                break;
            case 2:
                result.setText("You Loose );");
                break;
        }
    }

    public void ChooseSciccors(View view) {
        playerChoice.setImageResource(R.drawable.scissors);
        tem2 = roll();
        switch(tem2){
            case 0:
                result.setText("You Loose );");
                break;
            case 1:
                result.setText("You Win !!!");
                break;
            case 2:
                result.setText("Tie");
                break;
        }
    }

    public void chooseRock(View view) {
        playerChoice.setImageResource(R.drawable.rock);
        tem2 = roll();
        switch(tem2){
            case 0:
                result.setText("Tie");
                break;
            case 1:
                result.setText("You Loose );");
                break;
            case 2:
                result.setText("You Win !!!");
                break;
        }
    }
}