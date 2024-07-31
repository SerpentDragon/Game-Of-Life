#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include <unordered_map>
#include <SDL2/SDL_image.h>

namespace fs = std::filesystem;

class TextureManager
{
public:

    static std::shared_ptr<TextureManager> get_manager();

    SDL_Texture* get_texture(const std::string&) const;

    void set_renderer(SDL_Renderer*);

    void load_textures();

private:

    TextureManager();

    TextureManager(const TextureManager&) = delete;

    TextureManager(TextureManager&&) noexcept = delete;

    TextureManager& operator=(const TextureManager&) = delete;

    TextureManager& operator=(TextureManager&&) noexcept = delete;

    void load_all_textures_from_dir(const std::string&);

private:

    static std::shared_ptr<TextureManager> manager_;

    std::string prefix_;

    SDL_Renderer* renderer_;

    mutable std::unordered_map<std::string, SDL_Texture*> textures_;
};