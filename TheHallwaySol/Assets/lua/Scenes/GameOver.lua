gameover = {
    entities = {"defaultCamera", "sceneLight","UI"}
}

UI = {
    Active=true,
    Components = {"Transform"},
    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    Children={
        entities={"GameOverText","MainMenuButton","SelectLevelButton"},
        GameOverText={
            Active= true,
            Components={"Text", "Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Text={
                Active = true,
                Background = false,
                Border = false,
                Style= "TheHallway/StaticText",
                Name = "GameOverText",
                Text = "YOU CANNOT ESCAPE",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.15,-0.1  },
                Size = {1000,250}
                },
        },
        MainMenuButton = {
            Active =true,
            Components={"Button", "Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Button={
            Active = true,
            Enable = true, 
            Type = "Button",
            Style= "TheHallway/Button",
            Name = "GOMainButton",
            Text = "Main Menu",
            TLColor = "FFA20410",
            TRColor = "FFA20410",
            BLColor = "FFA20410",
            BRColor = "FFA20410",
            Position = {0.3,0.35},
            Size = {400,100},
            CallBackFunction = "gOtoMainMenu"
        },},
        SelectLevelButton = {
            Active =true,
            Components={"Button", "Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Button={
            Active = true,
            Enable = true, 
            Type = "Button",
            Style= "TheHallway/Button",
            Name = "GOSelectButton",
            Text = "Select Level",
            TLColor = "FFA20410",
            TRColor = "FFA20410",
            BLColor = "FFA20410",
            BRColor = "FFA20410",
            Position = {0.3,0.7},
            Size = {400,100},
            CallBackFunction = "gOtoLvlSelector"
        },
    }
}
}
sceneLight = {
    Active = true,
    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}
defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MenuCtrl",
        Background = {0.46,0.49,0.48},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}
