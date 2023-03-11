package com.example.w01b

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import kotlin.random.Random

class MainActivity : AppCompatActivity() {
    private var score = 0;
    private var r1 = 0;
    private var r2 = 0;
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        score = 0
        roll();
    }

    private fun roll(){
        findViewById<TextView>(R.id.points).text = "Punkty: " + score
        r1 = Random.nextInt(10)
        r2 = Random.nextInt(10)
        findViewById<Button>(R.id.leftClick).text = "" + r1
        findViewById<Button>(R.id.rightClick).text = "" + r2
    }

    fun buttonClickRight(view: View) {
        if(r2>=r1){
            score++
            Toast.makeText(this, "Super", Toast.LENGTH_SHORT).show()
        }else{
            score--
            Toast.makeText(this, "Słabiutko", Toast.LENGTH_SHORT).show()
        }
        roll()
    }
    fun buttonClickLeft(view: View) {
        if(r1>=r2){
            score++
            Toast.makeText(this, "Super", Toast.LENGTH_SHORT).show()
        }else{
            score--
            Toast.makeText(this, "Słabiutko", Toast.LENGTH_SHORT).show()
        }
        roll()
    }
}