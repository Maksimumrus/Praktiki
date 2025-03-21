package com.example.pr_1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{

    private static final int SETTINGS_REQUEST = 1;
    private TextView tvColor, tvVolume, tvDifficulty;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = findViewById(R.id.button);
        tvColor = findViewById(R.id.tvColor);
        tvVolume = findViewById(R.id.tvVolume);
        tvDifficulty = findViewById(R.id.tvDifficulty);

        button.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(MainActivity.this, Second.class);
                startActivityForResult(intent, SETTINGS_REQUEST);
            }
        });
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == SETTINGS_REQUEST && resultCode == RESULT_OK)
        {
            String color = data.getStringExtra("color");
            int volume = data.getIntExtra("volume", 0);
            int difficulty = data.getIntExtra("difficulty", 1);

            tvColor.setText("Цвет Фона: " + color);
            tvVolume.setText("Громкость: " + volume);
            tvDifficulty.setText("Сложности: " + difficulty);
        }
    }
}
