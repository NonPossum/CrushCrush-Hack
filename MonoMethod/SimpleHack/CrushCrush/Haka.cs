using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.UI;

namespace CrushCrush
{
    public class Loader
    {
        private static GameObject gameObject = new GameObject();

        public static void LoadCrush()
        {
            gameObject.AddComponent<Haka>();
            GameObject.DontDestroyOnLoad(gameObject);
        }
        public static void UnLoadCrush()
        {
            GameObject.Destroy(gameObject);
        }


    }

    class Haka : MonoBehaviour
    {
        public static Kiss k = new Kiss();

        public void OnGUI()
        {
            if (GUI.Button(new Rect(50, 50, 100, 50), "HACK!11"))
            {
                GameState.CurrentState.GetComponent<Audio>().PlayOnce(Audio.AudioFile.GirlUnlock);

                GameState.TotalTime = int.MaxValue;
                GameState.Diamonds.Value = int.MaxValue;
                GameState.Money.Value = double.MaxValue;
                GameState.UnlockedHobbies = int.MaxValue;
                GameState.TotalIncome.Value = double.MaxValue;
                GameState.UniverseReady.Value = true;
                GameState.HeartCount.Value = long.MaxValue;

            }
        }

    }
}
