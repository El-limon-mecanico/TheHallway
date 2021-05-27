Wall ={
    Active = true,
    Tag = "Wall",
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer ={
        Mesh = "Cube",
        Material = "TheHallway/Wall"
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {1,1,1},
        RotationConstrains = {1,1,1}
    }
}