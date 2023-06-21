package com.example.w02a

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import kotlin.random.Random

class MainActivity : AppCompatActivity() {
    var tem1 = 0;
    var tem2 = 0;
    lateinit var cpuChoice: ImageView
    lateinit var playerChoice: ImageView
    lateinit var result: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        result = findViewById<TextView>(R.id.resoult)
        cpuChoice = findViewById<ImageView>(R.id.cpuChoise)
        playerChoice = findViewById<ImageView>(R.id.yourChoise)
    }
    fun roll(): Int{
        tem1 = Random.nextInt(3)
        when (tem1){
            0 -> cpuChoice.setImageResource(R.drawable.rock)
            1 -> cpuChoice.setImageResource(R.drawable.paper)
            2 -> cpuChoice.setImageResource(R.drawable.scissors)
        }
        return tem1
    }
    fun choosePaper(view: View) {
        playerChoice.setImageResource(R.drawable.paper)
        tem2 = roll()
        when(tem2){
            0 -> result.text = "You Win !!!"
            1 -> result.text = "Tie"
            2 -> result.text = "You Loose );"
        }
    }
    fun ChooseSciccors(view: View) {
        playerChoice.setImageResource(R.drawable.scissors)
        tem2 =roll()
        when(tem2){
            0 -> result.text = "You Loose );"
            1 -> result.text = "You Win !!!"
            2 -> result.text = "Tie"
        }
    }
    fun chooseRock(view: View) {
        playerChoice.setImageResource(R.drawable.rock)
        tem2 = roll()
        when(tem2){
            0 -> result.text = "Tie"
            1 -> result.text = "You Loose );"
            2 -> result.text = "You Win !!!"
        }
    }
}