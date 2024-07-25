package com.example.smartsafety

import android.graphics.drawable.Drawable
import android.os.Bundle
import android.view.View
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.ProgressBar
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.ValueEventListener
import com.google.firebase.database.collection.LLRBNode.Color
import com.google.firebase.database.ktx.database
import com.google.firebase.database.ktx.getValue
import com.google.firebase.ktx.Firebase
import kotlin.math.roundToInt

class MainActivity : AppCompatActivity() {

    private lateinit var dist:TextView
    private lateinit var bg:LinearLayout
    private lateinit var horn:ImageView
    val database = Firebase.database
    private lateinit var progressBar: ProgressBar
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        dist=findViewById(R.id.dist)
        bg=findViewById(R.id.bg)
        horn=findViewById(R.id.horn)
        progressBar = findViewById(R.id.progress_bar)

        val myRef = database.getReference("data")
        myRef.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                val value = dataSnapshot.getValue<String>()
                val op:Double= value?.toDouble()!!
                if(op>=50) {
                    bg.setBackgroundColor(resources.getColor(R.color.green))
                    horn.visibility=View.GONE
                }else{
                    bg.setBackgroundColor(resources.getColor(R.color.red))
                    horn.visibility= View.VISIBLE
                }
            }

            override fun onCancelled(error: DatabaseError) {
                Toast.makeText(baseContext, "Unable to read data", Toast.LENGTH_SHORT).show()
            }
        })

    }
}
