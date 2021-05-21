menuPrincipal = {
    entities = {"defaultCamera", "UI"}
}

defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Active = true,
        Position = {25, 750,25},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Active = true,
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {25,0,25},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    }
}

UI = {
    Active = true,
    Components = {"Transform", "Light", "Button"},

    Transform = {
        Active = true,
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        Active = true,
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    },

    Button = {
        Active = true,
        Enable = true,
        Style = "WindowsLook/Button",
        Name  = "NuevaPartidaBoton",
        Text  = "Nueva Partida",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.5,0.5},
        Size = {100,100},
        CallBackFunction = "botonPresionado"
    }
}